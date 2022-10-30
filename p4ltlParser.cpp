// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "p4ltlParser.hpp"


// Unqualified %code blocks.
#line 26 "p4ltlparser.ypp"

    #include "p4ltlScanner.hpp"    
    #undef yylex
    #define yylex(x) scanner->lex(x)

#line 51 "p4ltlParser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 7 "p4ltlparser.ypp"
namespace P4LTL {
#line 124 "p4ltlParser.cpp"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  Parser::Parser (Scanner* scanner_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value ()
  {
    switch (this->type_get ())
    {
      case 39: // p4ltl
      case 40: // texpr
      case 41: // predicate
      case 42: // term
      case 43: // identifier
        value.move< AstNode* > (std::move (that.value));
        break;

      case 35: // NAME
        value.move< const char* > (std::move (that.value));
        break;

      case 36: // INT
        value.move< int > (std::move (that.value));
        break;

      default:
        break;
    }

  }
#endif

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->type_get ())
    {
      case 39: // p4ltl
      case 40: // texpr
      case 41: // predicate
      case 42: // term
      case 43: // identifier
        value.copy< AstNode* > (YY_MOVE (that.value));
        break;

      case 35: // NAME
        value.copy< const char* > (YY_MOVE (that.value));
        break;

      case 36: // INT
        value.copy< int > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
    {
      case 39: // p4ltl
      case 40: // texpr
      case 41: // predicate
      case 42: // term
      case 43: // identifier
        value.move< AstNode* > (YY_MOVE (s.value));
        break;

      case 35: // NAME
        value.move< const char* > (YY_MOVE (s.value));
        break;

      case 36: // INT
        value.move< int > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_type.
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  Parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  Parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }


  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_number_type
  Parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.type_get ())
    {
      case 39: // p4ltl
      case 40: // texpr
      case 41: // predicate
      case 42: // term
      case 43: // identifier
        value.YY_MOVE_OR_COPY< AstNode* > (YY_MOVE (that.value));
        break;

      case 35: // NAME
        value.YY_MOVE_OR_COPY< const char* > (YY_MOVE (that.value));
        break;

      case 36: // INT
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.type_get ())
    {
      case 39: // p4ltl
      case 40: // texpr
      case 41: // predicate
      case 42: // term
      case 43: // identifier
        value.move< AstNode* > (YY_MOVE (that.value));
        break;

      case 35: // NAME
        value.move< const char* > (YY_MOVE (that.value));
        break;

      case 36: // INT
        value.move< int > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 39: // p4ltl
      case 40: // texpr
      case 41: // predicate
      case 42: // term
      case 43: // identifier
        value.copy< AstNode* > (that.value);
        break;

      case 35: // NAME
        value.copy< const char* > (that.value);
        break;

      case 36: // INT
        value.copy< int > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 39: // p4ltl
      case 40: // texpr
      case 41: // predicate
      case 42: // term
      case 43: // identifier
        value.move< AstNode* > (that.value);
        break;

      case 35: // NAME
        value.move< const char* > (that.value);
        break;

      case 36: // INT
        value.move< int > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 39: // p4ltl
      case 40: // texpr
      case 41: // predicate
      case 42: // term
      case 43: // identifier
        yylhs.value.emplace< AstNode* > ();
        break;

      case 35: // NAME
        yylhs.value.emplace< const char* > ();
        break;

      case 36: // INT
        yylhs.value.emplace< int > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 65 "p4ltlparser.ypp"
    {yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); root = yylhs.value.as < AstNode* > ();
    }
#line 757 "p4ltlParser.cpp"
    break;

  case 3:
#line 70 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = new BinaryTemporalOperator(BinaryTemporalOperator::BinaryTemporalOperatorType::And, yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ());}
#line 763 "p4ltlParser.cpp"
    break;

  case 4:
#line 73 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = new BinaryTemporalOperator(BinaryTemporalOperator::BinaryTemporalOperatorType::Or, yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ()); }
#line 769 "p4ltlParser.cpp"
    break;

  case 5:
#line 76 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = new BinaryTemporalOperator(BinaryTemporalOperator::BinaryTemporalOperatorType::Implies, yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ()); }
#line 775 "p4ltlParser.cpp"
    break;

  case 6:
#line 79 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = new BinaryTemporalOperator(BinaryTemporalOperator::BinaryTemporalOperatorType::Until, yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ()); }
#line 781 "p4ltlParser.cpp"
    break;

  case 7:
#line 82 "p4ltlparser.ypp"
        { // a W b == Ga || a U b
        AstNode* globala = new UnaryTemporalOperator(UnaryTemporalOperator::UnaryTemporalOperatorType::Global, yystack_[2].value.as < AstNode* > ());
        AstNode* aUb = new BinaryTemporalOperator(BinaryTemporalOperator::BinaryTemporalOperatorType::Until, yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ());
        yylhs.value.as < AstNode* > () = new BinaryTemporalOperator(BinaryTemporalOperator::BinaryTemporalOperatorType::Or, 
                globala, aUb);
    }
#line 792 "p4ltlParser.cpp"
    break;

  case 8:
#line 90 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = new BinaryTemporalOperator(BinaryTemporalOperator::BinaryTemporalOperatorType::Release, yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ()); }
#line 798 "p4ltlParser.cpp"
    break;

  case 9:
#line 93 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = new UnaryTemporalOperator(UnaryTemporalOperator::UnaryTemporalOperatorType::Global, yystack_[1].value.as < AstNode* > ());}
#line 804 "p4ltlParser.cpp"
    break;

  case 10:
#line 96 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = new UnaryTemporalOperator(UnaryTemporalOperator::UnaryTemporalOperatorType::Final, yystack_[1].value.as < AstNode* > ()); }
#line 810 "p4ltlParser.cpp"
    break;

  case 11:
#line 99 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = new UnaryTemporalOperator(UnaryTemporalOperator::UnaryTemporalOperatorType::Next, yystack_[1].value.as < AstNode* > ()); }
#line 816 "p4ltlParser.cpp"
    break;

  case 12:
#line 102 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = new UnaryTemporalOperator(UnaryTemporalOperator::UnaryTemporalOperatorType::Not, yystack_[0].value.as < AstNode* > ()); }
#line 822 "p4ltlParser.cpp"
    break;

  case 13:
#line 105 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = yystack_[1].value.as < AstNode* > (); }
#line 828 "p4ltlParser.cpp"
    break;

  case 14:
#line 108 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = new P4LTLAtomicProposition(yystack_[1].value.as < AstNode* > ()); }
#line 834 "p4ltlParser.cpp"
    break;

  case 15:
#line 113 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = new Drop(); }
#line 840 "p4ltlParser.cpp"
    break;

  case 16:
#line 115 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = new Forward(yystack_[1].value.as < AstNode* > ()); }
#line 846 "p4ltlParser.cpp"
    break;

  case 17:
#line 117 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = new Apply(yystack_[1].value.as < const char* > ()); }
#line 852 "p4ltlParser.cpp"
    break;

  case 18:
#line 119 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = new Apply(yystack_[3].value.as < const char* > (), yystack_[1].value.as < const char* > ()); }
#line 858 "p4ltlParser.cpp"
    break;

  case 19:
#line 121 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = new Valid(yystack_[1].value.as < const char* > ()); }
#line 864 "p4ltlParser.cpp"
    break;

  case 20:
#line 123 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = new ExtendedComparativeOperator(ExtendedComparativeOperator::ExtendedComparativeOperatorType::eq, yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ()); }
#line 870 "p4ltlParser.cpp"
    break;

  case 21:
#line 125 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = new ExtendedComparativeOperator(ExtendedComparativeOperator::ExtendedComparativeOperatorType::gt, yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ()); }
#line 876 "p4ltlParser.cpp"
    break;

  case 22:
#line 127 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = new ExtendedComparativeOperator(ExtendedComparativeOperator::ExtendedComparativeOperatorType::geq, yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ()); }
#line 882 "p4ltlParser.cpp"
    break;

  case 23:
#line 129 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = new ExtendedComparativeOperator(ExtendedComparativeOperator::ExtendedComparativeOperatorType::neq, yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ()); }
#line 888 "p4ltlParser.cpp"
    break;

  case 24:
#line 131 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = new ExtendedComparativeOperator(ExtendedComparativeOperator::ExtendedComparativeOperatorType::lt, yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ()); }
#line 894 "p4ltlParser.cpp"
    break;

  case 25:
#line 133 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = new ExtendedComparativeOperator(ExtendedComparativeOperator::ExtendedComparativeOperatorType::leq, yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ()); }
#line 900 "p4ltlParser.cpp"
    break;

  case 26:
#line 136 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = new BinaryPredicateOperator(BinaryPredicateOperator::BinaryPredicateOperatorType::And, yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ()); }
#line 906 "p4ltlParser.cpp"
    break;

  case 27:
#line 138 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = new BinaryPredicateOperator(BinaryPredicateOperator::BinaryPredicateOperatorType::Or, yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ()); }
#line 912 "p4ltlParser.cpp"
    break;

  case 28:
#line 140 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = new BinaryPredicateOperator(BinaryPredicateOperator::BinaryPredicateOperatorType::Implies, yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ()); }
#line 918 "p4ltlParser.cpp"
    break;

  case 29:
#line 142 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = yystack_[1].value.as < AstNode* > (); }
#line 924 "p4ltlParser.cpp"
    break;

  case 30:
#line 144 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = new UnaryPredicateOperator(UnaryPredicateOperator::UnaryPredicateOperatorType::Not, yystack_[0].value.as < AstNode* > ()); }
#line 930 "p4ltlParser.cpp"
    break;

  case 31:
#line 149 "p4ltlparser.ypp"
        {// currently we don't support multiaccessor
        yylhs.value.as < AstNode* > () = new ArrayAccessExprssion(yystack_[3].value.as < AstNode* > (),yystack_[1].value.as < AstNode* > ()); }
#line 937 "p4ltlParser.cpp"
    break;

  case 32:
#line 152 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = new OldExpression(yystack_[1].value.as < const char* > ()); }
#line 943 "p4ltlParser.cpp"
    break;

  case 33:
#line 154 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = new Key(yystack_[3].value.as < const char* > (), yystack_[1].value.as < const char* > ()); }
#line 949 "p4ltlParser.cpp"
    break;

  case 34:
#line 156 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = new BinaryTermOperator(BinaryTermOperator::BinaryTermOperatorType::Plus, yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ()); }
#line 955 "p4ltlParser.cpp"
    break;

  case 35:
#line 158 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = new BinaryTermOperator(BinaryTermOperator::BinaryTermOperatorType::Minus, yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ()); }
#line 961 "p4ltlParser.cpp"
    break;

  case 36:
#line 160 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = new BinaryTermOperator(BinaryTermOperator::BinaryTermOperatorType::Multiply, yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ()); }
#line 967 "p4ltlParser.cpp"
    break;

  case 37:
#line 162 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = yystack_[1].value.as < AstNode* > (); }
#line 973 "p4ltlParser.cpp"
    break;

  case 38:
#line 164 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 979 "p4ltlParser.cpp"
    break;

  case 39:
#line 166 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = new IntLiteral(yystack_[0].value.as < int > ()); }
#line 985 "p4ltlParser.cpp"
    break;

  case 40:
#line 168 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = new BooleanLiteral(true); }
#line 991 "p4ltlParser.cpp"
    break;

  case 41:
#line 170 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = new BooleanLiteral(false); }
#line 997 "p4ltlParser.cpp"
    break;

  case 42:
#line 175 "p4ltlparser.ypp"
        {yylhs.value.as < AstNode* > () = new Name(yystack_[0].value.as < const char* > ()); }
#line 1003 "p4ltlParser.cpp"
    break;


#line 1007 "p4ltlParser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -23;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
       1,    -4,     1,    -3,     6,     7,     1,    16,   138,    -2,
      88,     1,     1,     1,   -23,   -23,     1,     1,     1,     1,
       1,     1,    -2,    12,   -23,    17,    21,    -2,    22,    46,
     -23,   -23,   -23,   -23,   116,   119,    14,   -23,    96,   104,
     112,   -23,   -23,   -23,    42,   145,   138,   120,    44,    20,
      30,    45,   -23,    53,    55,   -23,    -2,    -2,    -2,    30,
      30,    30,    30,    30,    30,    30,    30,    30,    30,   -23,
     -23,   -23,   -23,   -23,    48,    30,    -1,    73,    79,   102,
     -23,    95,   131,    58,    58,    93,    93,    58,    58,    58,
      58,   -23,    52,    99,   -23,    50,   -23,   -23,   -23,   103,
     -23,   157,   159,   -23,   -23
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,     0,     0,     0,     0,     0,     0,     0,     2,     0,
       0,     0,     0,     0,    12,     1,     0,     0,     0,     0,
       0,     0,     0,     0,    15,     0,     0,     0,     0,     0,
      40,    41,    42,    39,     0,     0,    38,    13,     0,     0,
       0,     6,     7,     8,     3,     4,     5,     0,     0,     0,
       0,     0,    30,     0,     0,    14,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     9,
      10,    11,    29,    37,     0,     0,     0,     0,     0,     0,
      26,    27,    28,    20,    23,    34,    35,    21,    22,    24,
      25,    36,     0,     0,    17,     0,    16,    19,    32,     0,
      31,     0,     0,    18,    33
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -23,   -23,    80,    -9,   -22,   -23
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,     7,     8,    34,    35,    36
  };

  const signed char
  Parser::yytable_[] =
  {
      48,     9,    11,    22,     1,    96,     2,    23,    24,    25,
      26,    12,    13,    47,     3,     4,    15,    49,    52,     5,
      27,    68,    50,     6,    61,    62,    51,    53,    76,    28,
      29,    30,    31,    32,    33,    75,    67,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    80,    81,    82,
      73,    54,    93,    95,    94,    74,    73,    16,    17,    18,
     100,    28,    29,    30,    31,    32,    33,    59,    60,    61,
      62,    63,    64,    65,    66,    61,    62,    61,    62,    97,
      77,    67,    10,    61,    62,    98,    14,    67,    78,    67,
      79,    38,    39,    40,    37,    67,    41,    42,    43,    44,
      45,    46,    69,    16,    17,    18,    99,    19,    20,    21,
      70,    16,    17,    18,    56,    19,    20,    21,    71,    16,
      17,    18,    55,    19,    20,    21,    72,    16,    17,    18,
      67,    19,    20,    21,   101,    56,    57,    58,   102,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      56,    57,    58,    16,    17,    18,    67,    19,    20,    21,
      16,    17,    18,   103,    19,   104
  };

  const signed char
  Parser::yycheck_[] =
  {
      22,     5,     5,     5,     3,     6,     5,     9,    10,    11,
      12,     5,     5,    22,    13,    14,     0,     5,    27,    18,
      22,     7,     5,    22,    25,    26,     5,     5,    50,    31,
      32,    33,    34,    35,    36,     5,    37,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    56,    57,    58,
       6,     5,     4,    75,     6,    35,     6,    15,    16,    17,
       8,    31,    32,    33,    34,    35,    36,    23,    24,    25,
      26,    27,    28,    29,    30,    25,    26,    25,    26,     6,
      35,    37,     2,    25,    26,     6,     6,    37,    35,    37,
      35,    11,    12,    13,     6,    37,    16,    17,    18,    19,
      20,    21,     6,    15,    16,    17,     4,    19,    20,    21,
       6,    15,    16,    17,    19,    19,    20,    21,     6,    15,
      16,    17,     6,    19,    20,    21,     6,    15,    16,    17,
      37,    19,    20,    21,    35,    19,    20,    21,    35,    19,
      20,    21,    23,    24,    25,    26,    27,    28,    29,    30,
      19,    20,    21,    15,    16,    17,    37,    19,    20,    21,
      15,    16,    17,     6,    19,     6
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     3,     5,    13,    14,    18,    22,    39,    40,     5,
      40,     5,     5,     5,    40,     0,    15,    16,    17,    19,
      20,    21,     5,     9,    10,    11,    12,    22,    31,    32,
      33,    34,    35,    36,    41,    42,    43,     6,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    41,    42,     5,
       5,     5,    41,     5,     5,     6,    19,    20,    21,    23,
      24,    25,    26,    27,    28,    29,    30,    37,     7,     6,
       6,     6,     6,     6,    35,     5,    42,    35,    35,    35,
      41,    41,    41,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    42,     4,     6,    42,     6,     6,     6,     4,
       8,    35,    35,     6,     6
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    38,    39,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    43
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     3,     3,     3,     3,     3,     3,     4,
       4,     4,     2,     3,     4,     1,     4,     4,     6,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     4,     4,     6,     3,     3,     3,     3,     1,     1,
       1,     1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "$end", "error", "$undefined", "AP", "COMMA", "LPAR", "RPAR",
  "LBRACKET", "RBRACKET", "APPLY", "DROP", "FWD", "VALID", "ALWAYS",
  "EVENTUALLY", "UNTIL", "WEAKUNTIL", "RELEASE", "NEXT", "AND", "OR",
  "IMPLIES", "NEG", "EQ", "NEQ", "PLUS", "MINUS", "GT", "GEQ", "LT", "LEQ",
  "OLD", "KEY", "TRUE", "FALSE", "NAME", "INT", "MULTIPLY", "$accept",
  "p4ltl", "texpr", "predicate", "term", "identifier", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  Parser::yyrline_[] =
  {
       0,    64,    64,    69,    72,    75,    78,    81,    89,    92,
      95,    98,   101,   104,   107,   112,   114,   116,   118,   120,
     122,   124,   126,   128,   130,   132,   135,   137,   139,   141,
     143,   148,   151,   153,   155,   157,   159,   161,   163,   165,
     167,   169,   174
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37
    };
    const int user_token_number_max_ = 292;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

#line 7 "p4ltlparser.ypp"
} // P4LTL
#line 1509 "p4ltlParser.cpp"

#line 177 "p4ltlparser.ypp"

/* void yyerror (const char *message)
{
	fprintf(stderr, "Error: %s\n", message);
} */

void P4LTL::Parser::error(const std::string& msg) {
    std::cerr << msg << '\n';
}

/* int main()
{
    yyparse();
    // std::cout << "Parse result: " <<  yyparse() << std::endl;
    if(root != nullptr)
        std::cout << "P4LTL: " + root->toString() << std::endl;
    else
        std::cout << "Root is empty. But Why?" << std::endl;
} */
