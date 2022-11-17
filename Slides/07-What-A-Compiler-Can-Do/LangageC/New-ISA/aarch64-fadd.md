(define_insn "add<mode>3"
  [(set (match_operand:GPF_F16 0 "register_operand" "=w")
	(plus:GPF_F16
	 (match_operand:GPF_F16 1 "register_operand" "w")
	 (match_operand:GPF_F16 2 "register_operand" "w")))]
  "TARGET_FLOAT"
  "fadd\\t%<s>0, %<s>1, %<s>2"
  [(set_attr "type" "fadd<stype>")]
)
