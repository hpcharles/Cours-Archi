;; fma - expand fma into patterns with the accumulator operand first since
;; reusing the accumulator results in better register allocation.
;; The register allocator considers copy preferences in operand order,
;; so this prefers fmadd s0, s1, s2, s0 over fmadd s1, s1, s2, s0.

(define_expand "fma<mode>4"
  [(set (match_operand:GPF_F16 0 "register_operand")
	(fma:GPF_F16 (match_operand:GPF_F16 1 "register_operand")
		     (match_operand:GPF_F16 2 "register_operand")
		     (match_operand:GPF_F16 3 "register_operand")))]
  "TARGET_FLOAT"
)

(define_insn "*aarch64_fma<mode>4"
  [(set (match_operand:GPF_F16 0 "register_operand" "=w")
	(fma:GPF_F16 (match_operand:GPF_F16 2 "register_operand" "w")
		     (match_operand:GPF_F16 3 "register_operand" "w")
		     (match_operand:GPF_F16 1 "register_operand" "w")))]
  "TARGET_FLOAT"
  "fmadd\\t%<s>0, %<s>2, %<s>3, %<s>1"
  [(set_attr "type" "fmac<stype>")]
)
