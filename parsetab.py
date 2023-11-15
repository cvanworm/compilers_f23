
# parsetab.py
# This file is automatically generated. Do not edit.
# pylint: disable=W,C,R
_tabversion = '3.10'

_lr_method = 'LALR'

_lr_signature = 'ASSIGN ASSIGN_DIVIDE ASSIGN_MINUS ASSIGN_MOD ASSIGN_MULTIPLY ASSIGN_PLUS COMMA COMMENT DAND DCONSTANT DECREMENT DEQ DIVIDE DOR GEQ GT ICONSTANT ID INCREMENT KEYWORD K_DO K_DOUBLE K_ELSE K_EXIT K_FUNCTION K_IF K_INTEGER K_PRINT_DOUBLE K_PRINT_INTEGER K_PRINT_STRING K_PROCEDURE K_PROGRAM K_READ_DOUBLE K_READ_INTEGER K_READ_STRING K_RETURN K_STRING K_THEN K_WHILE LBRACKET LCURLY LEQ LPAREN LT MINUS MOD NE NOT PERIOD PLUS RBRACKET RCURLY RPAREN SCONSTANT SEMI TIMESprogram : K_PROGRAM ID LCURLY program_body RCURLYprogram_body : program_body program_bodyprogram_body : function\n                    | procedureprogram_body : epsilonfunction : K_FUNCTION K_INTEGER ID LPAREN RPAREN LCURLY statements RCURLYprocedure : K_PROCEDURE ID LPAREN parameter_list RPAREN LCURLY statements RCURLYparameter_list : parameter_list COMMA parameter\n                      | parameterparameter : K_INTEGER ID\n                | K_DOUBLE ID\n                | K_STRING IDparameter : epsilonstatements : statements statementsstatements : declare \n                  | assign \n                  | print \n                  | function_callstatements : epsilondeclare : K_INTEGER ID SEMI\n             | K_DOUBLE ID SEMIassign : ID ASSIGN ICONSTANT SEMI\n            | ID ASSIGN DCONSTANT SEMI\n            | ID ASSIGN SCONSTANT SEMI\n            | ID ASSIGN math SEMIprint : K_PRINT_INTEGER LPAREN ID RPAREN SEMI\n             | K_PRINT_STRING LPAREN SCONSTANT RPAREN SEMI\n             | K_PRINT_STRING LPAREN ID RPAREN SEMI\n             | K_PRINT_DOUBLE LPAREN ID RPAREN SEMIfunction_call : ID LPAREN ID RPAREN SEMImath : expressionexpression : expression PLUS term\n                | expression MINUS termexpression : termterm : term TIMES factor\n            | term DIVIDE factorterm : factorfactor : LPAREN expression RPAREN\n              | MINUS LPAREN expression RPARENfactor : ICONSTANT\n            | DCONSTANTfactor : IDepsilon :'
    
_lr_action_items = {'K_PROGRAM':([0,],[2,]),'$end':([1,12,],[0,-1,]),'ID':([2,10,13,20,21,22,30,31,33,35,36,37,38,39,40,41,45,47,48,49,52,53,54,56,66,68,73,74,75,76,77,78,79,80,81,96,97,98,99,100,],[3,14,15,27,28,29,34,34,46,34,-15,-16,-17,-18,-19,51,34,57,67,34,69,71,72,-20,57,-21,-22,-23,-24,-25,57,57,57,57,57,-30,-26,-27,-28,-29,]),'LCURLY':([3,24,25,],[4,30,31,]),'K_FUNCTION':([4,5,6,7,8,11,50,55,],[9,9,-3,-4,-5,9,-6,-7,]),'K_PROCEDURE':([4,5,6,7,8,11,50,55,],[10,10,-3,-4,-5,10,-6,-7,]),'RCURLY':([4,5,6,7,8,11,30,31,35,36,37,38,39,40,45,49,50,55,56,68,73,74,75,76,96,97,98,99,100,],[-43,12,-3,-4,-5,-2,-43,-43,50,-15,-16,-17,-18,-19,55,-14,-6,-7,-20,-21,-22,-23,-24,-25,-30,-26,-27,-28,-29,]),'K_INTEGER':([9,16,26,30,31,35,36,37,38,39,40,45,49,56,68,73,74,75,76,96,97,98,99,100,],[13,20,20,33,33,33,-15,-16,-17,-18,-19,33,33,-20,-21,-22,-23,-24,-25,-30,-26,-27,-28,-29,]),'LPAREN':([14,15,34,42,43,44,47,64,66,77,78,79,80,81,],[16,17,48,52,53,54,66,81,66,66,66,66,66,66,]),'K_DOUBLE':([16,26,30,31,35,36,37,38,39,40,45,49,56,68,73,74,75,76,96,97,98,99,100,],[21,21,41,41,41,-15,-16,-17,-18,-19,41,41,-20,-21,-22,-23,-24,-25,-30,-26,-27,-28,-29,]),'K_STRING':([16,26,],[22,22,]),'RPAREN':([16,17,18,19,23,26,27,28,29,32,57,63,65,67,69,70,71,72,82,83,84,90,91,92,93,94,95,101,],[-43,24,25,-9,-13,-43,-10,-11,-12,-8,-42,-34,-37,85,86,87,88,89,95,-40,-41,-32,-33,-35,-36,101,-38,-39,]),'COMMA':([16,18,19,23,26,27,28,29,32,],[-43,26,-9,-13,-43,-10,-11,-12,-8,]),'K_PRINT_INTEGER':([30,31,35,36,37,38,39,40,45,49,56,68,73,74,75,76,96,97,98,99,100,],[42,42,42,-15,-16,-17,-18,-19,42,42,-20,-21,-22,-23,-24,-25,-30,-26,-27,-28,-29,]),'K_PRINT_STRING':([30,31,35,36,37,38,39,40,45,49,56,68,73,74,75,76,96,97,98,99,100,],[43,43,43,-15,-16,-17,-18,-19,43,43,-20,-21,-22,-23,-24,-25,-30,-26,-27,-28,-29,]),'K_PRINT_DOUBLE':([30,31,35,36,37,38,39,40,45,49,56,68,73,74,75,76,96,97,98,99,100,],[44,44,44,-15,-16,-17,-18,-19,44,44,-20,-21,-22,-23,-24,-25,-30,-26,-27,-28,-29,]),'ASSIGN':([34,],[47,]),'SEMI':([46,51,57,58,59,60,61,62,63,65,83,84,85,86,87,88,89,90,91,92,93,95,101,],[56,68,-42,73,74,75,76,-31,-34,-37,-40,-41,96,97,98,99,100,-32,-33,-35,-36,-38,-39,]),'ICONSTANT':([47,66,77,78,79,80,81,],[58,83,83,83,83,83,83,]),'DCONSTANT':([47,66,77,78,79,80,81,],[59,84,84,84,84,84,84,]),'SCONSTANT':([47,53,],[60,70,]),'MINUS':([47,57,58,59,62,63,65,66,77,78,79,80,81,82,83,84,90,91,92,93,94,95,101,],[64,-42,-40,-41,78,-34,-37,64,64,64,64,64,64,78,-40,-41,-32,-33,-35,-36,78,-38,-39,]),'TIMES':([57,58,59,63,65,83,84,90,91,92,93,95,101,],[-42,-40,-41,79,-37,-40,-41,79,79,-35,-36,-38,-39,]),'DIVIDE':([57,58,59,63,65,83,84,90,91,92,93,95,101,],[-42,-40,-41,80,-37,-40,-41,80,80,-35,-36,-38,-39,]),'PLUS':([57,58,59,62,63,65,82,83,84,90,91,92,93,94,95,101,],[-42,-40,-41,77,-34,-37,77,-40,-41,-32,-33,-35,-36,77,-38,-39,]),}

_lr_action = {}
for _k, _v in _lr_action_items.items():
   for _x,_y in zip(_v[0],_v[1]):
      if not _x in _lr_action:  _lr_action[_x] = {}
      _lr_action[_x][_k] = _y
del _lr_action_items

_lr_goto_items = {'program':([0,],[1,]),'program_body':([4,5,11,],[5,11,11,]),'function':([4,5,11,],[6,6,6,]),'procedure':([4,5,11,],[7,7,7,]),'epsilon':([4,5,11,16,26,30,31,35,45,49,],[8,8,8,23,23,40,40,40,40,40,]),'parameter_list':([16,],[18,]),'parameter':([16,26,],[19,32,]),'statements':([30,31,35,45,49,],[35,45,49,49,49,]),'declare':([30,31,35,45,49,],[36,36,36,36,36,]),'assign':([30,31,35,45,49,],[37,37,37,37,37,]),'print':([30,31,35,45,49,],[38,38,38,38,38,]),'function_call':([30,31,35,45,49,],[39,39,39,39,39,]),'math':([47,],[61,]),'expression':([47,66,81,],[62,82,94,]),'term':([47,66,77,78,81,],[63,63,90,91,63,]),'factor':([47,66,77,78,79,80,81,],[65,65,65,65,92,93,65,]),}

_lr_goto = {}
for _k, _v in _lr_goto_items.items():
   for _x, _y in zip(_v[0], _v[1]):
       if not _x in _lr_goto: _lr_goto[_x] = {}
       _lr_goto[_x][_k] = _y
del _lr_goto_items
_lr_productions = [
  ("S' -> program","S'",1,None,None,None),
  ('program -> K_PROGRAM ID LCURLY program_body RCURLY','program',5,'p_program','yaccf23.py',13),
  ('program_body -> program_body program_body','program_body',2,'p_program_body','yaccf23.py',20),
  ('program_body -> function','program_body',1,'p_program_body_fp','yaccf23.py',24),
  ('program_body -> procedure','program_body',1,'p_program_body_fp','yaccf23.py',25),
  ('program_body -> epsilon','program_body',1,'p_program_body_empty','yaccf23.py',29),
  ('function -> K_FUNCTION K_INTEGER ID LPAREN RPAREN LCURLY statements RCURLY','function',8,'p_function','yaccf23.py',33),
  ('procedure -> K_PROCEDURE ID LPAREN parameter_list RPAREN LCURLY statements RCURLY','procedure',8,'p_procedure','yaccf23.py',39),
  ('parameter_list -> parameter_list COMMA parameter','parameter_list',3,'p_parameter_list','yaccf23.py',45),
  ('parameter_list -> parameter','parameter_list',1,'p_parameter_list','yaccf23.py',46),
  ('parameter -> K_INTEGER ID','parameter',2,'p_parameter','yaccf23.py',53),
  ('parameter -> K_DOUBLE ID','parameter',2,'p_parameter','yaccf23.py',54),
  ('parameter -> K_STRING ID','parameter',2,'p_parameter','yaccf23.py',55),
  ('parameter -> epsilon','parameter',1,'p_parameter_empty','yaccf23.py',60),
  ('statements -> statements statements','statements',2,'p_statements','yaccf23.py',65),
  ('statements -> declare','statements',1,'p_statements_dapf','yaccf23.py',69),
  ('statements -> assign','statements',1,'p_statements_dapf','yaccf23.py',70),
  ('statements -> print','statements',1,'p_statements_dapf','yaccf23.py',71),
  ('statements -> function_call','statements',1,'p_statements_dapf','yaccf23.py',72),
  ('statements -> epsilon','statements',1,'p_statements_empty','yaccf23.py',76),
  ('declare -> K_INTEGER ID SEMI','declare',3,'p_declare','yaccf23.py',80),
  ('declare -> K_DOUBLE ID SEMI','declare',3,'p_declare','yaccf23.py',81),
  ('assign -> ID ASSIGN ICONSTANT SEMI','assign',4,'p_assign','yaccf23.py',86),
  ('assign -> ID ASSIGN DCONSTANT SEMI','assign',4,'p_assign','yaccf23.py',87),
  ('assign -> ID ASSIGN SCONSTANT SEMI','assign',4,'p_assign','yaccf23.py',88),
  ('assign -> ID ASSIGN math SEMI','assign',4,'p_assign','yaccf23.py',89),
  ('print -> K_PRINT_INTEGER LPAREN ID RPAREN SEMI','print',5,'p_print','yaccf23.py',98),
  ('print -> K_PRINT_STRING LPAREN SCONSTANT RPAREN SEMI','print',5,'p_print','yaccf23.py',99),
  ('print -> K_PRINT_STRING LPAREN ID RPAREN SEMI','print',5,'p_print','yaccf23.py',100),
  ('print -> K_PRINT_DOUBLE LPAREN ID RPAREN SEMI','print',5,'p_print','yaccf23.py',101),
  ('function_call -> ID LPAREN ID RPAREN SEMI','function_call',5,'p_function_call','yaccf23.py',105),
  ('math -> expression','math',1,'p_math','yaccf23.py',109),
  ('expression -> expression PLUS term','expression',3,'p_expression','yaccf23.py',113),
  ('expression -> expression MINUS term','expression',3,'p_expression','yaccf23.py',114),
  ('expression -> term','expression',1,'p_expression_term','yaccf23.py',123),
  ('term -> term TIMES factor','term',3,'p_term','yaccf23.py',127),
  ('term -> term DIVIDE factor','term',3,'p_term','yaccf23.py',128),
  ('term -> factor','term',1,'p_term_factor','yaccf23.py',136),
  ('factor -> LPAREN expression RPAREN','factor',3,'p_factor_expr','yaccf23.py',140),
  ('factor -> MINUS LPAREN expression RPAREN','factor',4,'p_factor_expr','yaccf23.py',141),
  ('factor -> ICONSTANT','factor',1,'p_factor_num','yaccf23.py',152),
  ('factor -> DCONSTANT','factor',1,'p_factor_num','yaccf23.py',153),
  ('factor -> ID','factor',1,'p_factor_id','yaccf23.py',157),
  ('epsilon -> <empty>','epsilon',0,'p_epsilon','yaccf23.py',164),
]
