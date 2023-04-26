cmake_minimum_required(VERSION 3.19.0)
project(stella-interpreter VERSION 0.1.0)

set (Stella_Syntax
  src/Stella/Absyn.H
  src/Stella/Absyn.C
  src/Stella/Parser.H
  src/Stella/Parser.C
  src/Stella/ParserError.H
  src/Stella/Printer.H
  src/Stella/Printer.C
  src/Stella/Buffer.H
  src/Stella/Buffer.C
  src/Stella/Bison.H
  src/Stella/Lexer.C
)

set (SRCS
  src/Interpret.cpp
  src/Eval.h
  src/Eval.cpp
  src/TypeCheck.h
  src/TypeCheck.cpp
  src/VisitTypeCheck.h
  src/VisitTypeCheck.cpp
)

add_executable(stella-interpreter ${Stella_Syntax} ${SRCS})
set_property(TARGET stella-interpreter PROPERTY CXX_STANDARD 17)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

include(CTest)

add_test(NAME applying-non-function-1 COMMAND stella-interpreter typecheck ../tests/core/ill-typed/applying-non-function-1.stella)
add_test(NAME applying-non-function-2 COMMAND stella-interpreter typecheck ../tests/core/ill-typed/applying-non-function-2.stella)
add_test(NAME applying-non-function-3 COMMAND stella-interpreter typecheck ../tests/core/ill-typed/applying-non-function-3.stella)
add_test(NAME argument-type-mismatch-1 COMMAND stella-interpreter typecheck ../tests/core/ill-typed/argument-type-mismatch-1.stella)
add_test(NAME argument-type-mismatch-2 COMMAND stella-interpreter typecheck ../tests/core/ill-typed/argument-type-mismatch-2.stella)
add_test(NAME argument-type-mismatch-3 COMMAND stella-interpreter typecheck ../tests/core/ill-typed/argument-type-mismatch-3.stella)
add_test(NAME bad-if-1 COMMAND stella-interpreter typecheck ../tests/core/ill-typed/bad-if-1.stella)
add_test(NAME bad-if-2 COMMAND stella-interpreter typecheck ../tests/core/ill-typed/bad-if-2.stella)
add_test(NAME bad-succ-1 COMMAND stella-interpreter typecheck ../tests/core/ill-typed/bad-succ-1.stella)
add_test(NAME bad-succ-2 COMMAND stella-interpreter typecheck ../tests/core/ill-typed/bad-succ-2.stella)
add_test(NAME bad-succ-3 COMMAND stella-interpreter typecheck ../tests/core/ill-typed/bad-succ-3.stella)
add_test(NAME shadowed-variable-1 COMMAND stella-interpreter typecheck ../tests/core/ill-typed/shadowed-variable-1.stella)
add_test(NAME undefined-variable-1 COMMAND stella-interpreter typecheck ../tests/core/ill-typed/undefined-variable-1.stella)
add_test(NAME undefined-variable-2 COMMAND stella-interpreter typecheck ../tests/core/ill-typed/undefined-variable-2.stella)
add_test(NAME bad-squares-1 COMMAND stella-interpreter typecheck ../tests/core/ill-typed/bad-squares-1.stella)
add_test(NAME bad-squares-2 COMMAND stella-interpreter typecheck ../tests/core/ill-typed/bad-squares-2.stella)

add_test(NAME bad-pairs-1 COMMAND stella-interpreter typecheck ../tests/pairs/ill-typed/bad-pairs-1.stella)
add_test(NAME bad-pairs-2 COMMAND stella-interpreter typecheck ../tests/pairs/ill-typed/bad-pairs-2.stella)
add_test(NAME bad-pairs-3 COMMAND stella-interpreter typecheck ../tests/pairs/ill-typed/bad-pairs-3.stella)
add_test(NAME bad-pairs-4 COMMAND stella-interpreter typecheck ../tests/pairs/ill-typed/bad-pairs-4.stella)
add_test(NAME bad-sum-types-1 COMMAND stella-interpreter typecheck ../tests/sum-types/ill-typed/bad-sum-types-1.stella)
add_test(NAME bad-sum-types-2 COMMAND stella-interpreter typecheck ../tests/sum-types/ill-typed/bad-sum-types-2.stella)
add_test(NAME bad-sum-types-3 COMMAND stella-interpreter typecheck ../tests/sum-types/ill-typed/bad-sum-types-3.stella)
add_test(NAME bad-sum-types-4 COMMAND stella-interpreter typecheck ../tests/sum-types/ill-typed/bad-sum-types-4.stella)
add_test(NAME bad-sum-types-5 COMMAND stella-interpreter typecheck ../tests/sum-types/ill-typed/bad-sum-types-5.stella)
add_test(NAME bad-tuples-1 COMMAND stella-interpreter typecheck ../tests/tuples/ill-typed/bad-tuples-1.stella)
add_test(NAME bad-tuples-2 COMMAND stella-interpreter typecheck ../tests/tuples/ill-typed/bad-tuples-2.stella)


add_test(NAME bad-nat-1 COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/bad-nat-1.stella)
add_test(NAME applying-non-function-1_extended_tests COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/applying-non-function-1.stella)
add_test(NAME argument-type-mismatch-2_extended_tests COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/argument-type-mismatch-2.stella)
add_test(NAME bad-succ-3_extended_tests COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/bad-succ-3.stella)
add_test(NAME bad-logic-not-1 COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/bad-logic-not-1.stella)
add_test(NAME bad-abstraction COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/bad-abstraction.stella)
add_test(NAME bad-factorial-2 COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/bad-factorial-2.stella)
add_test(NAME nat__rec-parameters COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/nat__rec-parameters.stella)
add_test(NAME bad-succ-1_extended_tests COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/bad-succ-1.stella)
add_test(NAME bad-cmp-2 COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/bad-cmp-2.stella)
add_test(NAME applying-non-function-3_extended_tests COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/applying-non-function-3.stella)
add_test(NAME bad-if-1_extended_tests COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/bad-if-1.stella)
add_test(NAME bad-add-1 COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/bad-add-1.stella)
add_test(NAME my-mismatch COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/my-mismatch.stella)
add_test(NAME bad-nat-rec-1 COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/bad-nat-rec-1.stella)
add_test(NAME undefined-variable-3 COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/undefined-variable-3.stella)
add_test(NAME argument-type-mismatch-4 COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/argument-type-mismatch-4.stella)
add_test(NAME bad-cmp-6 COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/bad-cmp-6.stella)
add_test(NAME bad-iszero COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/bad-iszero.stella)
add_test(NAME shadowed-variable-2 COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/shadowed-variable-2.stella)
add_test(NAME bad-function-call COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/bad-function-call.stella)
add_test(NAME bad-cmp-4 COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/bad-cmp-4.stella)
add_test(NAME added-test-1 COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/added-test-1.stella)
add_test(NAME my-ill-test-2 COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/my-ill-test-2.stella)
add_test(NAME undefined-variable-1_extended_tests COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/undefined-variable-1.stella)
add_test(NAME bad-multiply-1 COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/bad-multiply-1.stella)
add_test(NAME invalid-not_ COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/invalid-not_.stella)
add_test(NAME my-ill-typed-2 COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/my-ill-typed-2.stella)
add_test(NAME bad-if-and-undefined-variable-1 COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/bad-if-and-undefined-variable-1.stella)
add_test(NAME bad-if-3 COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/bad-if-3.stella)
add_test(NAME bad-squares-1_extended_tests COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/bad-squares-1.stella)
add_test(NAME bad-succ-2_extended_tests COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/bad-succ-2.stella)
add_test(NAME bad-factorial-1 COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/bad-factorial-1.stella)
add_test(NAME bad-cmp-1 COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/bad-cmp-1.stella)
add_test(NAME argument-type-mismatch-3_extended_tests COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/argument-type-mismatch-3.stella)
add_test(NAME my-factorial COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/my-factorial.stella)
add_test(NAME bad-factorial COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/bad-factorial.stella)
add_test(NAME applying-non-function-2_extended_tests COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/applying-non-function-2.stella)
add_test(NAME argument-type-mismatch-1_extended_tests COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/argument-type-mismatch-1.stella)
add_test(NAME bad-cmp-3 COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/bad-cmp-3.stella)
add_test(NAME bad-nat-2 COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/bad-nat-2.stella)
add_test(NAME invalid-nat COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/invalid-nat.stella)
add_test(NAME function-mismatch COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/function-mismatch.stella)
add_test(NAME bad-if-4 COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/bad-if-4.stella)
add_test(NAME bad-higher-order-1 COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/bad-higher-order-1.stella)
add_test(NAME my-ill-typed-1 COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/my-ill-typed-1.stella)
add_test(NAME undefined-variable-2_extended_tests COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/undefined-variable-2.stella)
add_test(NAME added-test-2 COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/added-test-2.stella)
add_test(NAME bad-squares-2_extended_tests COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/bad-squares-2.stella)
add_test(NAME bad-nat-rec-2 COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/bad-nat-rec-2.stella)
add_test(NAME bad-logic-or-1 COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/bad-logic-or-1.stella)
add_test(NAME bad-return-type COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/bad-return-type.stella)
add_test(NAME application-param-type COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/application-param-type.stella)
add_test(NAME bad-if-2_extended_tests COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/bad-if-2.stella)
add_test(NAME shadowed-variable-1_extended_tests COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/shadowed-variable-1.stella)
add_test(NAME bad-cmp-5 COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/bad-cmp-5.stella)
add_test(NAME bad-logic-and-1 COMMAND stella-interpreter typecheck ../tests/extended_tests/ill-typed/bad-logic-and-1.stella)
add_test(NAME bad-records-1 COMMAND stella-interpreter typecheck ../tests/records/ill-typed/bad-records-1.stella)
add_test(NAME bad-records-2 COMMAND stella-interpreter typecheck ../tests/records/ill-typed/bad-records-2.stella)
add_test(NAME bad-refs-1 COMMAND stella-interpreter typecheck ../tests/references/ill-typed/bad-refs-1.stella)
add_test(NAME bad-refs-2 COMMAND stella-interpreter typecheck ../tests/references/ill-typed/bad-refs-2.stella)
add_test(NAME bad-refs-3 COMMAND stella-interpreter typecheck ../tests/references/ill-typed/bad-refs-3.stella)

add_test(NAME bad-subtyping-1 COMMAND stella-interpreter typecheck ../tests/subtyping/ill-typed/bad-subtyping-1.stella)
add_test(NAME bad-subtyping-2 COMMAND stella-interpreter typecheck ../tests/subtyping/ill-typed/bad-subtyping-2.stella)
add_test(NAME bad-subtyping-3 COMMAND stella-interpreter typecheck ../tests/subtyping/ill-typed/bad-subtyping-3.stella)
add_test(NAME bad-subtyping-4 COMMAND stella-interpreter typecheck ../tests/subtyping/ill-typed/bad-subtyping-4.stella)
add_test(NAME bad-subtyping-5 COMMAND stella-interpreter typecheck ../tests/subtyping/ill-typed/bad-subtyping-5.stella)

add_test(NAME bad-panic-1 COMMAND stella-interpreter typecheck ../tests/exceptions/ill-typed/bad-panic-1.stella)

add_test(NAME bad-general-recursion COMMAND stella-interpreter typecheck ../tests/recursions/ill-typed/bad-general-recursion.stella)
# add_test(NAME bad-fix COMMAND stella-interpreter typecheck ../tests/recursions/ill-typed/bad-fix.stella)

add_test(NAME bad-structurals-1 COMMAND stella-interpreter typecheck ../tests/structurals/ill-typed/bad-structurals-1.stella)
add_test(NAME structure-patterns-1 COMMAND stella-interpreter typecheck ../tests/structurals/ill-typed/structure-patterns.stella)

add_test(NAME bad_ignore COMMAND stella-interpreter typecheck ../tests/units/ill-typed/bad_ignore.stella)

set_tests_properties(
  bad-nat-1
  applying-non-function-1_extended_tests
  argument-type-mismatch-2_extended_tests
  bad-succ-3_extended_tests
  bad-logic-not-1
  bad-abstraction
  bad-factorial-2
  nat__rec-parameters
  bad-succ-1_extended_tests
  bad-cmp-2
  applying-non-function-3_extended_tests
  bad-if-1_extended_tests
  bad-add-1
  my-mismatch
  bad-nat-rec-1
  undefined-variable-3
  argument-type-mismatch-4
  bad-cmp-6
  bad-iszero
  shadowed-variable-2
  bad-function-call
  bad-cmp-4
  added-test-1
  my-ill-test-2
  undefined-variable-1_extended_tests
  bad-multiply-1
  invalid-not_
  my-ill-typed-2
  bad-if-and-undefined-variable-1
  bad-if-3
  bad-squares-1_extended_tests
  bad-succ-2_extended_tests
  bad-factorial-1
  bad-cmp-1
  argument-type-mismatch-3_extended_tests
  my-factorial
  bad-factorial
  applying-non-function-2_extended_tests
  argument-type-mismatch-1_extended_tests
  bad-cmp-3
  bad-nat-2
  invalid-nat
  function-mismatch
  bad-if-4
  bad-higher-order-1
  my-ill-typed-1
  undefined-variable-2_extended_tests
  added-test-2
  bad-squares-2_extended_tests
  bad-nat-rec-2
  bad-logic-or-1
  bad-return-type
  application-param-type
  bad-if-2_extended_tests
  shadowed-variable-1_extended_tests
  bad-cmp-5
  bad-logic-and-1
  bad-records-1
  bad-records-2
  bad-refs-1
  bad-refs-2
  bad-refs-3
  bad-subtyping-1
  bad-subtyping-2
  bad-subtyping-3
  bad-subtyping-4
  bad-subtyping-5

  bad-structurals-1 
  structure-patterns-1

  # bad-fix
  bad-general-recursion

  bad-panic-1
  bad_ignore

  bad-squares-1
  bad-squares-2
  applying-non-function-1
  applying-non-function-2
  applying-non-function-3
  argument-type-mismatch-1
  argument-type-mismatch-2
  argument-type-mismatch-3
  bad-if-1
  bad-if-2
  bad-succ-1
  bad-succ-2
  bad-succ-3
  shadowed-variable-1
  undefined-variable-1
  undefined-variable-2

  bad-pairs-1
  bad-pairs-2
  bad-pairs-3
  bad-pairs-4
  bad-sum-types-1
  bad-sum-types-2
  bad-sum-types-3
  bad-sum-types-4
  bad-sum-types-5
  bad-tuples-1
  bad-tuples-2
  PROPERTIES WILL_FAIL TRUE)

add_test(NAME factorial COMMAND stella-interpreter typecheck ../tests/core/well-typed/factorial.stella)
add_test(NAME increment_twice COMMAND stella-interpreter typecheck ../tests/core/well-typed/increment_twice.stella)
add_test(NAME higher-order-1 COMMAND stella-interpreter typecheck ../tests/core/well-typed/higher-order-1.stella)
add_test(NAME logical-operators COMMAND stella-interpreter typecheck ../tests/core/well-typed/logical-operators.stella)
add_test(NAME squares COMMAND stella-interpreter typecheck ../tests/core/well-typed/squares.stella)

add_test(NAME pairs-1 COMMAND stella-interpreter typecheck ../tests/pairs/well-typed/pairs-1.stella)
add_test(NAME sum-types-1 COMMAND stella-interpreter typecheck ../tests/sum-types/well-typed/sum-types-1.stella)
add_test(NAME sum-types-2 COMMAND stella-interpreter typecheck ../tests/sum-types/well-typed/sum-types-2.stella)
add_test(NAME sum-types-3 COMMAND stella-interpreter typecheck ../tests/sum-types/well-typed/sum-types-3.stella)
add_test(NAME tuples-1 COMMAND stella-interpreter typecheck ../tests/tuples/well-typed/tuples-1.stella)
add_test(NAME tuples-2 COMMAND stella-interpreter typecheck ../tests/tuples/well-typed/tuples-2.stella)


add_test(NAME my-well-typed-2 COMMAND stella-interpreter typecheck ../tests/extended_tests/well-typed/my-well-typed-2.stella)
add_test(NAME inner-if COMMAND stella-interpreter typecheck ../tests/extended_tests/well-typed/inner-if.stella)
add_test(NAME abstract-function COMMAND stella-interpreter typecheck ../tests/extended_tests/well-typed/abstract-function.stella)
add_test(NAME negate COMMAND stella-interpreter typecheck ../tests/extended_tests/well-typed/negate.stella)
add_test(NAME higher-order-2 COMMAND stella-interpreter typecheck ../tests/extended_tests/well-typed/higher-order-2.stella)
add_test(NAME good-if-2 COMMAND stella-interpreter typecheck ../tests/extended_tests/well-typed/good-if-2.stella)
add_test(NAME shadowed-variable-2_extended_tests COMMAND stella-interpreter typecheck ../tests/extended_tests/well-typed/shadowed-variable-2.stella)
add_test(NAME good-if COMMAND stella-interpreter typecheck ../tests/extended_tests/well-typed/good-if.stella)
add_test(NAME added-test-1_extended_tests COMMAND stella-interpreter typecheck ../tests/extended_tests/well-typed/added-test-1.stella)
add_test(NAME good-succ-2 COMMAND stella-interpreter typecheck ../tests/extended_tests/well-typed/good-succ-2.stella)
add_test(NAME decrement_twice COMMAND stella-interpreter typecheck ../tests/extended_tests/well-typed/decrement_twice.stella)
add_test(NAME nested COMMAND stella-interpreter typecheck ../tests/extended_tests/well-typed/nested.stella)
add_test(NAME applying-actual-function-3 COMMAND stella-interpreter typecheck ../tests/extended_tests/well-typed/applying-actual-function-3.stella)
add_test(NAME increment_twice_extended_tests COMMAND stella-interpreter typecheck ../tests/extended_tests/well-typed/increment_twice.stella)
add_test(NAME increment-triple COMMAND stella-interpreter typecheck ../tests/extended_tests/well-typed/increment-triple.stella)
add_test(NAME my-good-succ COMMAND stella-interpreter typecheck ../tests/extended_tests/well-typed/my-good-succ.stella)
add_test(NAME apply-increase COMMAND stella-interpreter typecheck ../tests/extended_tests/well-typed/apply-increase.stella)
add_test(NAME many-if COMMAND stella-interpreter typecheck ../tests/extended_tests/well-typed/many-if.stella)
add_test(NAME my-good-if COMMAND stella-interpreter typecheck ../tests/extended_tests/well-typed/my-good-if.stella)
add_test(NAME cubes COMMAND stella-interpreter typecheck ../tests/extended_tests/well-typed/cubes.stella)
add_test(NAME my-well-typed-1 COMMAND stella-interpreter typecheck ../tests/extended_tests/well-typed/my-well-typed-1.stella)
add_test(NAME squares_extended_tests COMMAND stella-interpreter typecheck ../tests/extended_tests/well-typed/squares.stella)
add_test(NAME my-test-2 COMMAND stella-interpreter typecheck ../tests/extended_tests/well-typed/my-test-2.stella)
add_test(NAME nat-to-bool COMMAND stella-interpreter typecheck ../tests/extended_tests/well-typed/nat-to-bool.stella)
add_test(NAME double-application COMMAND stella-interpreter typecheck ../tests/extended_tests/well-typed/double-application.stella)
add_test(NAME added-test-2_extended_tests COMMAND stella-interpreter typecheck ../tests/extended_tests/well-typed/added-test-2.stella)
add_test(NAME bool-to-nat COMMAND stella-interpreter typecheck ../tests/extended_tests/well-typed/bool-to-nat.stella)
add_test(NAME good-succ-1 COMMAND stella-interpreter typecheck ../tests/extended_tests/well-typed/good-succ-1.stella)
add_test(NAME higher-order-1_extended_tests COMMAND stella-interpreter typecheck ../tests/extended_tests/well-typed/higher-order-1.stella)
add_test(NAME records-1 COMMAND stella-interpreter typecheck ../tests/records/well-typed/records-1.stella)
add_test(NAME records-2 COMMAND stella-interpreter typecheck ../tests/records/well-typed/records-2.stella)
add_test(NAME refs-1 COMMAND stella-interpreter typecheck ../tests/references/well-typed/refs-1.stella)
add_test(NAME refs-2 COMMAND stella-interpreter typecheck ../tests/references/well-typed/refs-2.stella)
# add_test(NAME refs-3 COMMAND stella-interpreter typecheck ../tests/references/well-typed/refs-3.stella)
add_test(NAME refs-4 COMMAND stella-interpreter typecheck ../tests/references/well-typed/refs-4.stella)

add_test(NAME subtyping-1 COMMAND stella-interpreter typecheck ../tests/subtyping/well-typed/subtyping-1.stella)
add_test(NAME subtyping-2 COMMAND stella-interpreter typecheck ../tests/subtyping/well-typed/subtyping-2.stella)
add_test(NAME subtyping-3 COMMAND stella-interpreter typecheck ../tests/subtyping/well-typed/subtyping-3.stella)
add_test(NAME subtyping-4 COMMAND stella-interpreter typecheck ../tests/subtyping/well-typed/subtyping-4.stella)
add_test(NAME subtyping-5 COMMAND stella-interpreter typecheck ../tests/subtyping/well-typed/subtyping-5.stella)
add_test(NAME subtyping-6 COMMAND stella-interpreter typecheck ../tests/subtyping/well-typed/subtyping-6.stella)
add_test(NAME subtyping-7 COMMAND stella-interpreter typecheck ../tests/subtyping/well-typed/subtyping-7.stella)
add_test(NAME subtyping-8 COMMAND stella-interpreter typecheck ../tests/subtyping/well-typed/subtyping-8.stella)

# add_test(NAME panic-1 COMMAND stella-interpreter typecheck ../tests/exceptions/well-typed/panic-1.stella)
add_test(NAME panic-2 COMMAND stella-interpreter typecheck ../tests/exceptions/well-typed/panic-2.stella)
add_test(NAME panic-3 COMMAND stella-interpreter typecheck ../tests/exceptions/well-typed/panic-3.stella)

# add_test(NAME fix COMMAND stella-interpreter typecheck ../tests/recursions/well-typed/fix.stella)
add_test(NAME general-recursion COMMAND stella-interpreter typecheck ../tests/recursions/well-typed/general-recursion.stella)


add_test(NAME structurals-1 COMMAND stella-interpreter typecheck ../tests/structurals/well-typed/structurals-1.stella)
# add_test(NAME structure-patterns COMMAND stella-interpreter typecheck ../tests/structurals/well-typed/structure-patterns.stella)


add_test(NAME ignore COMMAND stella-interpreter typecheck ../tests/units/well-typed/ignore.stella)