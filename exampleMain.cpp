#include "p4ltlast.hpp"
#include "p4ltlParser.hpp"
#include "p4ltlScanner.hpp"
#include <string>
#include <sstream>
#include <vector>
// safe for example
using namespace std; 
using namespace P4LTL;  


// it's an ugly impl for using global vector
// yet it's enough for example
vector<AstNode*> allNodes;
void collectAllNodes(AstNode* root)
{
    allNodes.push_back(root);
    for(auto child: root->getOutgoingNodes())
    {
        collectAllNodes(child);
    }
}

vector<P4LTLAtomicProposition*> getAllAP(AstNode* root)
{
    allNodes.clear();
    collectAllNodes(root);
    vector<P4LTLAtomicProposition*> result;
    for(auto n: allNodes)
    {
        if(dynamic_cast<P4LTLAtomicProposition*>(n) != nullptr)
            result.push_back(dynamic_cast<P4LTLAtomicProposition*>(n));
    }
    return result;
}

int main() {
    // can parse any number of strings
    string p4ltl1 = "[](AP(hdr.ether == 0xffffffffffff * 2 + 3 / hdr.test))";
    string p4ltl2 = "Error!!!";
    string p4ltl3 = "[](AP(!drop) ==> AP((old(hdr.ipv4.ttl) != 0 && hdr.ipv4.ttl == old(hdr.ipv4.ttl) - 1) || (old(hdr.ipv4.ttl) == 0 && hdr.ipv4.ttl == 255)))";
    vector<string> strings = {p4ltl1, p4ltl2, p4ltl3};

    // processing
    for(int j = 0; j < strings.size(); ++j)
    {
        cout << "\n======= Processing string " << j + 1 << "=======" << endl;
        // init scanner and parser
        istringstream inputStringStream(strings[j]);
        P4LTL::Scanner scanner{ inputStringStream, std::cerr };
        P4LTL::AstNode* root = nullptr;    // root is the parse result
        P4LTL::Parser parser{ scanner, root};
        int result = parser.parse();
        if(result == 0 && root)
        {
            cout << "Gotcha! Here is the parse result: ";
            cout << root->toString() << endl;
            cout << "Now here's another example for getting all the atomic proposition: " << endl;
            // example of getting all the aps
            vector<P4LTLAtomicProposition*> result = getAllAP(root);
            for(int i = 0; i < result.size(); ++i)
            {
                cout << "AP" << i + 1 << ": " + result[i]->toString() << endl;
            }
        }
        else
            cout << "Can't get root/Root is empty, maybe a parse error." << endl;
    }
}