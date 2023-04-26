#include "VisitTypeCheck.h"
#include <iostream>

namespace Stella
{ // Function to combine List of Parameters and ReturnType to unit TypeFun
    TypeFun *CombineFun(std::vector<Type *> Parameters, Type *ReturnType)
    {
        ListType *ListOfTypes = new ListType();
        for (int i = Parameters.size() - 1; i >= 0; --i)
            ListOfTypes = consListType(Parameters[i], ListOfTypes);

        TypeFun *Result = new TypeFun(ListOfTypes, ReturnType);

        return Result;
    }

    // Function to combine List of Types to TypeTuple
    TypeTuple *CombineTuple(std::vector<Type *> Types)
    {
        ListType *ListOfTypes = new ListType();
        for (int i = Types.size() - 1; i >= 0; --i)
            ListOfTypes = consListType(Types[i], ListOfTypes);

        TypeTuple *Result = new TypeTuple(ListOfTypes);

        return Result;
    }

    bool simpleCompare(Type *firstType, Type *secondType)
    {
        auto showner = new ShowAbsyn();
        std::string firstTypeStr = showner->show(firstType);
        std::string secondTypeStr = showner->show(secondType);

        if (firstTypeStr == secondTypeStr)
            return true;
        else
            return false;
    }

    bool typesumCompare(Type *firstType, Type *secondType)
    {
        auto showner = new ShowAbsyn();
        std::string firstTypeStr = showner->show(firstType);
        if (firstTypeStr.size() > 8 && firstTypeStr.substr(0, 8) == "(TypeSum")
        {
            TypeSum *secondTypeSum = (TypeSum *)secondType;
            TypeSum *firstTypeSum = (TypeSum *)firstType;

            if (simpleCompare(secondTypeSum->type_2, new TypeBottom()) == false && simpleCompare(secondTypeSum->type_1, new TypeBottom()) == false)
                return (typesumCompare(firstTypeSum->type_1, secondTypeSum->type_1) &&
                        typesumCompare(firstTypeSum->type_2, secondTypeSum->type_2));

            if (simpleCompare(secondTypeSum->type_1, new TypeBottom()) == false)
                return typesumCompare(firstTypeSum->type_1, secondTypeSum->type_1);

            if (simpleCompare(secondTypeSum->type_2, new TypeBottom()) == false)
                return typesumCompare(firstTypeSum->type_2, secondTypeSum->type_2);

            if (simpleCompare(secondTypeSum->type_2, new TypeBottom()) && simpleCompare(secondTypeSum->type_1, new TypeBottom()))
                return false;
            return false;
        }
        else
        {
            return simpleCompare(firstType, secondType);
        }
    };

    bool compareTypes(Type *subType, Type *superType);

    // Добавить в Record проверку что имена параметров различные
    bool typerecordCompare(Type *subType, Type *superType)
    {
        auto showner = new ShowAbsyn();
        std::string subTypeStr = showner->show(subType);
        std::string superTypeStr = showner->show(superType);
        if (subTypeStr.size() > 11 && subTypeStr.substr(0, 11) == "(TypeRecord" &&
            superTypeStr.size() > 11 && superTypeStr.substr(0, 11) == "(TypeRecord")
        {
            TypeRecord *subTypeRecord = (TypeRecord *)subType;
            TypeRecord *superTypeRecord = (TypeRecord *)superType;

            bool ifSubType = true;
            for (ListRecordFieldType::iterator i = superTypeRecord->listrecordfieldtype_->begin(); i != superTypeRecord->listrecordfieldtype_->end(); ++i)
            {
                ARecordFieldType *AFTi = (ARecordFieldType *)(*i);
                bool entered = false;
                bool found = false;

                for (ListRecordFieldType::iterator j = subTypeRecord->listrecordfieldtype_->begin(); j != subTypeRecord->listrecordfieldtype_->end(); ++j)
                {
                    ARecordFieldType *AFTj = (ARecordFieldType *)(*j);
                    // i - parameter of superType
                    // j - parameter of subType

                    if (AFTj->stellaident_ == AFTi->stellaident_ && compareTypes(AFTj->type_, AFTi->type_))
                        found = true;

                    if (AFTj->stellaident_ == AFTi->stellaident_)
                        entered = true;
                }
                if (entered == false || found == false)
                    ifSubType = false;
            }

            return ifSubType;
        }
        else
            return false;
    }

    bool typefunCompare(Type *subType, Type *superType)
    {
        auto showner = new ShowAbsyn();
        std::string subTypeStr = showner->show(subType);
        std::string superTypeStr = showner->show(superType);
        if (subTypeStr.size() > 8 && subTypeStr.substr(0, 8) == "(TypeFun" &&
            superTypeStr.size() > 8 && superTypeStr.substr(0, 8) == "(TypeFun")
        {
            TypeFun *subTypeFun = (TypeFun *)subType;
            TypeFun *superTypeFun = (TypeFun *)superType;

            bool ifSubType = true;
            ListType::iterator j = subTypeFun->listtype_->begin();
            for (ListType::iterator i = superTypeFun->listtype_->begin();
                 i != superTypeFun->listtype_->end() && j < subTypeFun->listtype_->end(); ++i, ++j)
            {
                // i - parameter of superType
                // j - parameter of subType
                if (compareTypes((*i), (*j)) == false)
                {
                    ifSubType = false;
                }
            }

            return (compareTypes(subTypeFun->type_, superTypeFun->type_) && ifSubType);
        }
        else
            return false;
    };

    // Function to check if to Types are equal
    bool compareTypes(Type *subType, Type *superType)
    {
        auto showner = new ShowAbsyn();
        std::string subTypeStr = showner->show(subType);
        std::string superTypeStr = showner->show(superType);
        if (subTypeStr == showner->show(new TypeBottom()) || superTypeStr == showner->show(new TypeTop()))
            return true;

        if (subTypeStr == showner->show(new TypeTop()) || superTypeStr == showner->show(new TypeBottom()))
            return false;

        if (subTypeStr.size() > 8 && subTypeStr.substr(0, 8) == "(TypeSum")
        {
            std::string botStr = showner->show(new TypeBottom());
            if (subTypeStr.find(botStr) != std::string::npos)
                return typesumCompare(superType, subType);
            else
                return typesumCompare(subType, superType);
        }
        if (subTypeStr.size() > 8 && subTypeStr.substr(0, 8) == "(TypeFun")
        {
            return typefunCompare(subType, superType);
        }
        if (subTypeStr.size() > 11 && subTypeStr.substr(0, 11) == "(TypeRecord")
        {
            return typerecordCompare(subType, superType);
        }

        return simpleCompare(subType, superType);
    }

    // Get textual representation of the Visitable node
    std::string getNodeID(Visitable *node)
    {
        PrintAbsyn *printer = new PrintAbsyn();

        std::string nodeID = printer->print(node);
        nodeID = nodeID.substr(0, nodeID.size() - 1);

        return nodeID;
    }

    // Check if given variable of function is already defined
    void VisitTypeCheck::ifDefined(std::string ID, int line_number)
    {
        if (this->declearedVariables.count(ID) == 0)
        {
            std::cout << "Error: " << ID << " is not defined" << std::endl
                      << "On the line: " << line_number << std::endl;
            ;
            exit(1);
        }
    }

    // Check if given Type is a function type
    bool ifTypeFun(Type *firstType)
    {
        auto showner = new ShowAbsyn();
        std::string firstTypeStr = showner->show(firstType);
        if (firstTypeStr.size() > 8 && firstTypeStr.substr(0, 8) == "(TypeFun")
            return true;
        else
            return false;
    }

    void nullptrCheck(Type *someType, int line_number, int char_number)
    {
        if (someType == nullptr)
        {
            std::cout << "Error: expression is not specified" << std::endl
                      << "On the line: " << line_number << std::endl
                      << "Character number: " << char_number << std::endl;
            exit(1);
        }
    }

    // Print collected variable's declarations
    void VisitTypeCheck::printDeclVars()
    {
        std::cout << std::endl
                  << "Map size: " << this->declearedVariables.size() << std::endl;

        std::cout << "Map Arguments:" << std::endl;
        for (auto item : this->declearedVariables)
            std::cout << item.first << " //IS OF TYPE// " << printer->print(item.second.type) << std::endl;
    }
    void VisitTypeCheck::visitProgram(Program *t) {}                   // abstract class
    void VisitTypeCheck::visitLanguageDecl(LanguageDecl *t) {}         // abstract class
    void VisitTypeCheck::visitExtension(Extension *t) {}               // abstract class
    void VisitTypeCheck::visitDecl(Decl *t) {}                         // abstract class
    void VisitTypeCheck::visitLocalDecl(LocalDecl *t) {}               // abstract class
    void VisitTypeCheck::visitAnnotation(Annotation *t) {}             // abstract class
    void VisitTypeCheck::visitParamDecl(ParamDecl *t) {}               // abstract class
    void VisitTypeCheck::visitReturnType(ReturnType *t) {}             // abstract class
    void VisitTypeCheck::visitThrowType(ThrowType *t) {}               // abstract class
    void VisitTypeCheck::visitType(Type *t) {}                         // abstract class
    void VisitTypeCheck::visitMatchCase(MatchCase *t) {}               // abstract class
    void VisitTypeCheck::visitOptionalTyping(OptionalTyping *t) {}     // abstract class
    void VisitTypeCheck::visitPatternData(PatternData *t) {}           // abstract class
    void VisitTypeCheck::visitExprData(ExprData *t) {}                 // abstract class
    void VisitTypeCheck::visitPattern(Pattern *t) {}                   // abstract class
    void VisitTypeCheck::visitLabelledPattern(LabelledPattern *t) {}   // abstract class
    void VisitTypeCheck::visitBinding(Binding *t) {}                   // abstract class
    void VisitTypeCheck::visitExpr(Expr *t) {}                         // abstract class
    void VisitTypeCheck::visitPatternBinding(PatternBinding *t) {}     // abstract class
    void VisitTypeCheck::visitVariantFieldType(VariantFieldType *t) {} // abstract class
    void VisitTypeCheck::visitRecordFieldType(RecordFieldType *t) {}   // abstract class
    void VisitTypeCheck::visitTyping(Typing *t) {}                     // abstract class

    void VisitTypeCheck::visitAProgram(AProgram *a_program)
    {
        /* Code For AProgram Goes Here */

        if (a_program->languagedecl_)
            a_program->languagedecl_->accept(this);
        if (a_program->listextension_)
            a_program->listextension_->accept(this);
        if (a_program->listdecl_)
            a_program->listdecl_->accept(this);

        // If main is not specified
        if (this->declearedVariables.count("main") == 0)
        {
            std::cout << "Error: no main function in the code" << std::endl;
            exit(1);
        }

        // this->printDeclVars();
    }

    void VisitTypeCheck::visitLanguageCore(LanguageCore *language_core)
    {
        /* Code For LanguageCore Goes Here */
    }

    void VisitTypeCheck::visitAnExtension(AnExtension *an_extension)
    {
        /* Code For AnExtension Goes Here */

        if (an_extension->listextensionname_)
            an_extension->listextensionname_->accept(this);
    }

    void VisitTypeCheck::visitDeclFun(DeclFun *decl_fun)
    {
        // Scope realisation
        std::unordered_map<std::string, VariableDescriptions> declearedVariablesCopy;
        declearedVariablesCopy.insert(this->declearedVariables.begin(), this->declearedVariables.end());

        if (decl_fun->listannotation_)
            decl_fun->listannotation_->accept(this);
        visitStellaIdent(decl_fun->stellaident_);

        // Collecting parameter types
        if (decl_fun->listparamdecl_)
            decl_fun->listparamdecl_->accept(this);
        std::vector<Type *> listparamdeclCopy = this->getReturnTypesList();

        if (decl_fun->returntype_)
            decl_fun->returntype_->accept(this);
        Type *returntype_Type = this->getLastReturn();

        // Adding function into the Scope space
        TypeFun *FunctionType = CombineFun(listparamdeclCopy, returntype_Type);
        this->addVariableDecl(decl_fun->stellaident_, FunctionType, 0);

        if (decl_fun->throwtype_)
            decl_fun->throwtype_->accept(this);
        if (decl_fun->listdecl_)
            decl_fun->listdecl_->accept(this);
        if (decl_fun->expr_)
            decl_fun->expr_->accept(this);
        Type *expr_Type = this->getLastReturn();

        // Check if there is return type
        if ((std::string)showner->show(decl_fun->returntype_) == "NoReturnType")
        {
            std::cout << "Error: no return type in the function " << std::endl
                      << "Function name: " << decl_fun->stellaident_ << std::endl;
            exit(1);
        }

        // Check if the return expression is correctly handled
        nullptrCheck(expr_Type, decl_fun->expr_->line_number, decl_fun->expr_->char_number);

        // Check if the return expression is of function retur type
        if (compareTypes(expr_Type, returntype_Type) == false)
        {
            std::cout << "Error: incorrect return expression type in function \"" << decl_fun->stellaident_ << '"' << std::endl
                      << "Expected: " << showner->show(returntype_Type) << std::endl
                      << "But got: " << showner->show(expr_Type) << std::endl
                      << "On the line: " << decl_fun->expr_->line_number << std::endl;
            exit(1);
        }

        // Clearning from infunction declaration
        this->declearedVariables.clear();
        declearedVariables.insert(declearedVariablesCopy.begin(), declearedVariablesCopy.end());

        // From function declaration we save only function name with it's type
        this->addVariableDecl(decl_fun->stellaident_, FunctionType, 0);
    }

    void VisitTypeCheck::visitDeclTypeAlias(DeclTypeAlias *decl_type_alias)
    {
        /* Code For DeclTypeAlias Goes Here */

        visitStellaIdent(decl_type_alias->stellaident_);
        if (decl_type_alias->type_)
            decl_type_alias->type_->accept(this);
    }

    void VisitTypeCheck::visitDeclExceptionType(DeclExceptionType *decl_exception_type)
    {
        /* Code For DeclExceptionType Goes Here */

        if (decl_exception_type->type_)
            decl_exception_type->type_->accept(this);
    }

    void VisitTypeCheck::visitDeclExceptionVariant(DeclExceptionVariant *decl_exception_variant)
    {
        /* Code For DeclExceptionVariant Goes Here */

        visitStellaIdent(decl_exception_variant->stellaident_);
        if (decl_exception_variant->type_)
            decl_exception_variant->type_->accept(this);
    }

    void VisitTypeCheck::visitAssign(Assign *assign)
    {
        /* Code For Assign Goes Here */

        if (assign->expr_1)
            assign->expr_1->accept(this);
        Type *expr_1Type = this->getLastReturn();
        if (assign->expr_2)
            assign->expr_2->accept(this);
        Type *expr_2Type = this->getLastReturn();

        if (compareTypes(expr_1Type, new TypeRef(expr_2Type)) == false)
        {
            std::cout << "Error: incorect types in the assignment statement" << std::endl
                      << "Left: " << showner->show(expr_1Type) << std::endl
                      << "Right: " << showner->show(expr_2Type) << std::endl;
            exit(1);
        }

        this->setLastReturn(new TypeUnit());
    }

    void VisitTypeCheck::visitRef(Ref *ref)
    {
        /* Code For Ref Goes Here */

        if (ref->expr_)
            ref->expr_->accept(this);
        Type *expr_Type = this->getLastReturn();

        this->setLastReturn(new TypeRef(expr_Type));
    }

    void VisitTypeCheck::visitDeref(Deref *deref)
    {
        /* Code For Deref Goes Here */

        if (deref->expr_)
            deref->expr_->accept(this);
        TypeRef *expr_Type = (TypeRef *)this->getLastReturn();
        if (expr_Type->type_ == nullptr)
        {
            std::cout << "Error: incorrect dereferencing" << std::endl
                      << "On the line: " << deref->line_number << std::endl
                      << "Character number: " << deref->char_number << std::endl;
            exit(1);
        }

        this->setLastReturn(expr_Type->type_);
    }

    void VisitTypeCheck::visitPanic(Panic *panic)
    {
        /* Code For Panic Goes Here */
        this->setLastReturn(new TypeBottom());
    }

    void VisitTypeCheck::visitThrow(Throw *throw_)
    {
        /* Code For Throw Goes Here */

        if (throw_->expr_)
            throw_->expr_->accept(this);
    }

    void VisitTypeCheck::visitTryCatch(TryCatch *try_catch)
    {
        /* Code For TryCatch Goes Here */

        if (try_catch->expr_1)
            try_catch->expr_1->accept(this);
        if (try_catch->pattern_)
            try_catch->pattern_->accept(this);
        if (try_catch->expr_2)
            try_catch->expr_2->accept(this);
    }

    void VisitTypeCheck::visitTryWith(TryWith *try_with)
    {
        /* Code For TryWith Goes Here */

        if (try_with->expr_1)
            try_with->expr_1->accept(this);
        if (try_with->expr_2)
            try_with->expr_2->accept(this);
    }

    void VisitTypeCheck::visitALocalDecl(ALocalDecl *a_local_decl)
    {
        /* Code For ALocalDecl Goes Here */

        if (a_local_decl->decl_)
            a_local_decl->decl_->accept(this);
    }

    void VisitTypeCheck::visitInlineAnnotation(InlineAnnotation *inline_annotation)
    {
        /* Code For InlineAnnotation Goes Here */
    }

    void VisitTypeCheck::visitAParamDecl(AParamDecl *a_param_decl)
    {
        /* Code For AParamDecl Goes Here */

        visitStellaIdent(a_param_decl->stellaident_);
        if (a_param_decl->type_)
            a_param_decl->type_->accept(this);

        Type *type_Type = this->getLastReturn();

        this->addVariableDecl(a_param_decl->stellaident_, type_Type, 1);
        this->setLastReturn(type_Type);
    }

    void VisitTypeCheck::visitNoReturnType(NoReturnType *no_return_type)
    {
        /* Code For NoReturnType Goes Here */
    }

    void VisitTypeCheck::visitSomeReturnType(SomeReturnType *some_return_type)
    {
        /* Code For SomeReturnType Goes Here */

        if (some_return_type->type_)
            some_return_type->type_->accept(this);
        Type *retType = this->getLastReturn();
        this->setLastReturn(retType);
    }

    void VisitTypeCheck::visitNoThrowType(NoThrowType *no_throw_type)
    {
        /* Code For NoThrowType Goes Here */
    }

    void VisitTypeCheck::visitSomeThrowType(SomeThrowType *some_throw_type)
    {
        /* Code For SomeThrowType Goes Here */

        if (some_throw_type->listtype_)
            some_throw_type->listtype_->accept(this);
    }

    void VisitTypeCheck::visitTypeFun(TypeFun *type_fun)
    {
        /* Code For TypeFun Goes Here */
        // fn (Nat, Nat) -> Nat
        // fn (Nat) -> fn (Nat) -> Nat

        if (type_fun->listtype_)
            type_fun->listtype_->accept(this);
        std::vector<Type *> listparamdeclCopy = this->getReturnTypesList();
        if (type_fun->type_)
            type_fun->type_->accept(this);
        Type *expr_Type = this->getLastReturn();

        // Check if the function name is handled correctly
        nullptrCheck(expr_Type, type_fun->line_number, type_fun->char_number);

        TypeFun *FunctionType = CombineFun(listparamdeclCopy, expr_Type);

        // Return function type
        this->setLastReturn(FunctionType);
    }

    void VisitTypeCheck::visitTypeRec(TypeRec *type_rec)
    {
        /* Code For TypeRec Goes Here */

        visitStellaIdent(type_rec->stellaident_);
        if (type_rec->type_)
            type_rec->type_->accept(this);
    }

    void VisitTypeCheck::visitTypeSum(TypeSum *type_sum)
    {
        /* Code For TypeSum Goes Here */

        if (type_sum->type_1)
            type_sum->type_1->accept(this);
        Type *type_1Type = this->getLastReturn();
        if (type_sum->type_2)
            type_sum->type_2->accept(this);
        Type *type_2Type = this->getLastReturn();

        TypeSum *SumType = new TypeSum(type_1Type, type_2Type);

        this->setLastReturn(SumType);
    }

    void VisitTypeCheck::visitTypeTuple(TypeTuple *type_tuple)
    {
        /* Code For TypeTuple Goes Here */

        if (type_tuple->listtype_)
            type_tuple->listtype_->accept(this);
        std::vector<Type *> listparamdeclCopy = this->getReturnTypesList();

        TypeTuple *TupleType = CombineTuple(listparamdeclCopy);

        this->setLastReturn(TupleType);
    }

    void VisitTypeCheck::visitTypeRecord(TypeRecord *type_record)
    {
        /* Code For TypeRecord Goes Here */
        if (type_record->listrecordfieldtype_)
            type_record->listrecordfieldtype_->accept(this);

        this->setLastReturn(type_record);
    }

    void VisitTypeCheck::visitTypeVariant(TypeVariant *type_variant)
    {
        /* Code For TypeVariant Goes Here */

        if (type_variant->listvariantfieldtype_)
            type_variant->listvariantfieldtype_->accept(this);
    }

    void VisitTypeCheck::visitTypeList(TypeList *type_list)
    {
        /* Code For TypeList Goes Here */

        if (type_list->type_)
            type_list->type_->accept(this);
    }

    void VisitTypeCheck::visitTypeBool(TypeBool *type_bool)
    {
        /* Code For TypeBool Goes Here */
        this->setLastReturn(new TypeBool());
    }

    void VisitTypeCheck::visitTypeNat(TypeNat *type_nat)
    {
        /* Code For TypeNat Goes Here */
        this->setLastReturn(new TypeNat());
    }

    void VisitTypeCheck::visitTypeUnit(TypeUnit *type_unit)
    {
        /* Code For TypeUnit Goes Here */
        this->setLastReturn(new TypeUnit());
    }

    void VisitTypeCheck::visitTypeTop(TypeTop *type_top)
    {
        /* Code For TypeTop Goes Here */
        this->setLastReturn(new TypeTop());
    }

    void VisitTypeCheck::visitTypeBottom(TypeBottom *type_bottom)
    {
        /* Code For TypeBottom Goes Here */
        this->setLastReturn(new TypeBottom());
    }

    void VisitTypeCheck::visitTypeRef(TypeRef *type_ref)
    {
        /* Code For TypeRef Goes Here */

        if (type_ref->type_)
            type_ref->type_->accept(this);

        this->setLastReturn(type_ref);
    }

    void VisitTypeCheck::visitTypeVar(TypeVar *type_var)
    {
        /* Code For TypeVar Goes Here */
        ifDefined(type_var->stellaident_, type_var->line_number);

        visitStellaIdent(type_var->stellaident_);

        // Return variable type
        this->setLastReturn(this->declearedVariables[type_var->stellaident_].type);
    }

    void VisitTypeCheck::visitAMatchCase(AMatchCase *a_match_case)
    {
        /* Code For AMatchCase Goes Here */
        // Scope realisation
        std::unordered_map<std::string, VariableDescriptions> declearedVariablesCopy;
        declearedVariablesCopy.insert(this->declearedVariables.begin(), this->declearedVariables.end());

        if (a_match_case->pattern_)
            a_match_case->pattern_->accept(this);

        if (a_match_case->expr_)
            a_match_case->expr_->accept(this);
        Type *expr_Type = this->getLastReturn();

        nullptrCheck(expr_Type, a_match_case->expr_->line_number, a_match_case->expr_->char_number);

        // Clearning from infunction declaration
        this->declearedVariables.clear();
        declearedVariables.insert(declearedVariablesCopy.begin(), declearedVariablesCopy.end());
        this->setLastReturn(expr_Type);
    }

    void VisitTypeCheck::visitNoTyping(NoTyping *no_typing)
    {
        /* Code For NoTyping Goes Here */
    }

    void VisitTypeCheck::visitSomeTyping(SomeTyping *some_typing)
    {
        /* Code For SomeTyping Goes Here */

        if (some_typing->type_)
            some_typing->type_->accept(this);
    }

    void VisitTypeCheck::visitNoPatternData(NoPatternData *no_pattern_data)
    {
        /* Code For NoPatternData Goes Here */
    }

    void VisitTypeCheck::visitSomePatternData(SomePatternData *some_pattern_data)
    {
        /* Code For SomePatternData Goes Here */

        if (some_pattern_data->pattern_)
            some_pattern_data->pattern_->accept(this);
    }

    void VisitTypeCheck::visitNoExprData(NoExprData *no_expr_data)
    {
        /* Code For NoExprData Goes Here */
    }

    void VisitTypeCheck::visitSomeExprData(SomeExprData *some_expr_data)
    {
        /* Code For SomeExprData Goes Here */

        if (some_expr_data->expr_)
            some_expr_data->expr_->accept(this);
    }

    void VisitTypeCheck::visitPatternVariant(PatternVariant *pattern_variant)
    {
        /* Code For PatternVariant Goes Here */

        visitStellaIdent(pattern_variant->stellaident_);
        if (pattern_variant->patterndata_)
            pattern_variant->patterndata_->accept(this);
    }

    void VisitTypeCheck::visitPatternInl(PatternInl *pattern_inl)
    {
        /* Code For PatternInl Goes Here */
        TypeSum *input = (TypeSum *)this->getInType();
        if (input == nullptr)
        {
            std::cout << "Error: incorrect parameters in the pattern inl" << std::endl
                      << "On the line: " << pattern_inl->line_number << std::endl
                      << "Character number" << pattern_inl->char_number << std::endl;
            exit(1);
        }

        if (input->type_1 == nullptr)
        {
            std::cout << "Error: incorrect parameters in the match" << std::endl;
            std::cout << "Expected: " << showner->show(this->getInType()) << std::endl
                      << "But got: " << showner->show(pattern_inl) << std::endl;
            exit(1);
        }

        this->setInType(input->type_1);
        if (pattern_inl->pattern_)
            pattern_inl->pattern_->accept(this);
    }

    void VisitTypeCheck::visitPatternInr(PatternInr *pattern_inr)
    {
        /* Code For PatternInr Goes Here */
        TypeSum *input = (TypeSum *)this->getInType();
        if (input == nullptr)
        {
            std::cout << "Error: incorrect parameters in the pattern inr" << std::endl
                      << "On the line: " << pattern_inr->line_number << std::endl
                      << "Character number" << pattern_inr->char_number << std::endl;
            exit(1);
        }

        if (input->type_2 == nullptr)
        {
            std::cout << "Error: incorrect parameters in the match" << std::endl;
            std::cout << "Expected: " << showner->show(this->getInType()) << std::endl
                      << "But got: " << showner->show(pattern_inr) << std::endl;
            exit(1);
        }

        this->setInType(input->type_2);
        if (pattern_inr->pattern_)
            pattern_inr->pattern_->accept(this);
    }

    void VisitTypeCheck::visitPatternTuple(PatternTuple *pattern_tuple)
    {
        /* Code For PatternTuple Goes Here */
        TypeTuple *input = (TypeTuple *)this->getInType();
        if (input == nullptr)
        {
            std::cout << "Error: incorrect parameters in the pattern tuple" << std::endl
                      << "On the line: " << pattern_tuple->line_number << std::endl
                      << "Character number" << pattern_tuple->char_number << std::endl;
            exit(1);
        }

        if (input->listtype_ == nullptr)
        {
            std::cout << "Error: incorrect parameters in the tuple" << std::endl;
            std::cout << "Expected: " << showner->show(this->getInType()) << std::endl
                      << "But got: " << showner->show(pattern_tuple) << std::endl;
            exit(1);
        }

        if (pattern_tuple->listpattern_)
            pattern_tuple->listpattern_->accept(this);
    }

    void VisitTypeCheck::visitPatternRecord(PatternRecord *pattern_record)
    {
        /* Code For PatternRecord Goes Here */
        TypeRecord *input = (TypeRecord *)this->getInType();
        if (input == nullptr)
        {
            std::cout << "Error: incorrect parameters in the pattern record" << std::endl
                      << "On the line: " << pattern_record->line_number << std::endl
                      << "Character number" << pattern_record->char_number << std::endl;
            exit(1);
        }

        if (input->listrecordfieldtype_ == nullptr)
        {
            std::cout << "Error: incorrect parameters in the tuple" << std::endl;
            std::cout << "Expected: " << showner->show(this->getInType()) << std::endl
                      << "But got: " << showner->show(pattern_record) << std::endl;
            exit(1);
        }

        if (pattern_record->listlabelledpattern_)
            pattern_record->listlabelledpattern_->accept(this);
    }

    void VisitTypeCheck::visitPatternList(PatternList *pattern_list)
    {
        /* Code For PatternList Goes Here */

        if (pattern_list->listpattern_)
            pattern_list->listpattern_->accept(this);
    }

    void VisitTypeCheck::visitPatternCons(PatternCons *pattern_cons)
    {
        /* Code For PatternCons Goes Here */

        if (pattern_cons->pattern_1)
            pattern_cons->pattern_1->accept(this);
        if (pattern_cons->pattern_2)
            pattern_cons->pattern_2->accept(this);
    }

    void VisitTypeCheck::visitPatternFalse(PatternFalse *pattern_false)
    {
        /* Code For PatternFalse Goes Here */
        Type *input = this->getInType();
        if (input == nullptr)
        {
            std::cout << "Error: incorrect parameters in the pattern false" << std::endl
                      << "On the line: " << pattern_false->line_number << std::endl
                      << "Character number" << pattern_false->char_number << std::endl;
            exit(1);
        }

        if (compareTypes(input, new TypeBool()) == false)
        {
            std::cout << "Error: incorrect parameters in the match" << std::endl;
            std::cout << "Expected: " << showner->show(input) << std::endl
                      << "But got: " << showner->show(new TypeBool()) << std::endl;
            exit(1);
        }
    }

    void VisitTypeCheck::visitPatternTrue(PatternTrue *pattern_true)
    {
        /* Code For PatternTrue Goes Here */
        Type *input = this->getInType();
        if (input == nullptr)
        {
            std::cout << "Error: incorrect parameters in the pattern true" << std::endl
                      << "On the line: " << pattern_true->line_number << std::endl
                      << "Character number" << pattern_true->char_number << std::endl;
            exit(1);
        }

        if (compareTypes(input, new TypeBool()) == false)
        {
            std::cout << "Error: incorrect parameters in the match" << std::endl;
            std::cout << "Expected: " << showner->show(input) << std::endl
                      << "But got: " << showner->show(new TypeBool()) << std::endl;
            exit(1);
        }
    }

    void VisitTypeCheck::visitPatternUnit(PatternUnit *pattern_unit)
    {
        /* Code For PatternUnit Goes Here */
        Type *input = this->getInType();
        if (input == nullptr)
        {
            std::cout << "Error: incorrect parameters in the pattern unit" << std::endl
                      << "On the line: " << pattern_unit->line_number << std::endl
                      << "Character number" << pattern_unit->char_number << std::endl;
            exit(1);
        }

        if (compareTypes(input, new TypeUnit()) == false)
        {
            std::cout << "Error: incorrect parameters in the match" << std::endl;
            std::cout << "Expected: " << showner->show(input) << std::endl
                      << "But got: " << showner->show(new TypeUnit()) << std::endl;
            exit(1);
        }
    }

    void VisitTypeCheck::visitPatternInt(PatternInt *pattern_int)
    {
        /* Code For PatternInt Goes Here */
        Type *input = this->getInType();
        if (input == nullptr)
        {
            std::cout << "Error: incorrect parameters in the pattern int" << std::endl
                      << "On the line: " << pattern_int->line_number << std::endl
                      << "Character number" << pattern_int->char_number << std::endl;
            exit(1);
        }

        if (compareTypes(input, new TypeNat()) == false)
        {
            std::cout << "Error: incorrect parameters in the match" << std::endl;
            std::cout << "Expected: " << showner->show(input) << std::endl
                      << "But got: " << showner->show(new TypeNat()) << std::endl;
            exit(1);
        }

        visitInteger(pattern_int->integer_);
    }

    void VisitTypeCheck::visitPatternSucc(PatternSucc *pattern_succ)
    {
        /* Code For PatternSucc Goes Here */
        Type *input = this->getInType();
        if (input == nullptr)
        {
            std::cout << "Error: incorrect parameters in the pattern succ" << std::endl
                      << "On the line: " << pattern_succ->line_number << std::endl
                      << "Character number" << pattern_succ->char_number << std::endl;
            exit(1);
        }

        if (compareTypes(input, new TypeNat()) == false)
        {
            std::cout << "Error: incorrect parameters in the match" << std::endl;
            std::cout << "Expected: " << showner->show(input) << std::endl
                      << "But got: " << showner->show(new TypeNat()) << std::endl;
            exit(1);
        }

        if (pattern_succ->pattern_)
            pattern_succ->pattern_->accept(this);
    }

    void VisitTypeCheck::visitPatternVar(PatternVar *pattern_var)
    {
        /* Code For PatternVar Goes Here */
        Type *input = this->getInType();
        if (input == nullptr)
        {
            std::cout << "Error: incorrect parameters in the pattern var" << std::endl
                      << "On the line: " << pattern_var->line_number << std::endl
                      << "Character number" << pattern_var->char_number << std::endl;
            exit(1);
        }

        visitStellaIdent(pattern_var->stellaident_);

        if (this->declearedVariables.count(pattern_var->stellaident_) == 0)
        {
            this->addVariableDecl(pattern_var->stellaident_, input, 0);
        }
        else
        {
            if (compareTypes(this->declearedVariables[pattern_var->stellaident_].type, input) == false)
            {
                std::cout << "Error: incorrect parameters in the match" << std::endl;
                std::cout << "Expected: " << showner->show(input) << std::endl
                          << "But got: " << showner->show(this->declearedVariables[pattern_var->stellaident_].type) << std::endl;
                exit(1);
            }
        }
    }

    void VisitTypeCheck::visitALabelledPattern(ALabelledPattern *a_labelled_pattern)
    {
        /* Code For ALabelledPattern Goes Here */
        Type *input = this->getInType();
        if (input == nullptr)
        {
            std::cout << "Error: incorrect parameters in the pattern record" << std::endl
                      << "On the line: " << a_labelled_pattern->line_number << std::endl
                      << "Character number" << a_labelled_pattern->char_number << std::endl;
            exit(1);
        }

        this->setInType(input);
        visitStellaIdent(a_labelled_pattern->stellaident_);
        if (a_labelled_pattern->pattern_)
            a_labelled_pattern->pattern_->accept(this);
    }

    void VisitTypeCheck::visitABinding(ABinding *a_binding)
    {
        /* Code For ABinding Goes Here */

        visitStellaIdent(a_binding->stellaident_);
        if (a_binding->expr_)
            a_binding->expr_->accept(this);
        Type *expr_Type = this->getLastReturn();

        nullptrCheck(expr_Type, a_binding->expr_->line_number, a_binding->expr_->char_number);

        // Return binding type
        this->setLastReturn(expr_Type);
    }

    void VisitTypeCheck::visitSequence(Sequence *sequence)
    {
        /* Code For Sequence Goes Here */

        if (sequence->expr_1)
            sequence->expr_1->accept(this);
        Type *expr_1Type = this->getLastReturn();

        nullptrCheck(expr_1Type, sequence->expr_1->line_number, sequence->expr_1->char_number);

        if (compareTypes(expr_1Type, new TypeUnit()) == false)
        {
            std::cout << "Error: incorrect parameters in the match" << std::endl;
            std::cout << "Expected: " << showner->show(new TypeUnit()) << std::endl
                      << "But got: " << showner->show(expr_1Type) << std::endl;
            exit(1);
        }

        if (sequence->expr_2)
            sequence->expr_2->accept(this);
        Type *expr_2Type = this->getLastReturn();

        nullptrCheck(expr_2Type, sequence->expr_2->line_number, sequence->expr_2->char_number);

        // Return sequence type
        this->setLastReturn(expr_2Type);
    }

    void VisitTypeCheck::visitIf(If *if_)
    {
        /* Code For If Goes Here */

        if (if_->expr_1)
            if_->expr_1->accept(this);
        Type *expr_1Type = this->getLastReturn();

        if (if_->expr_2)
            if_->expr_2->accept(this);
        Type *expr_2Type = this->getLastReturn();

        if (if_->expr_3)
            if_->expr_3->accept(this);
        Type *expr_3Type = this->getLastReturn();

        // Types Check
        nullptrCheck(expr_1Type, if_->expr_1->line_number, if_->expr_1->char_number);
        nullptrCheck(expr_2Type, if_->expr_2->line_number, if_->expr_2->char_number);
        nullptrCheck(expr_3Type, if_->expr_3->line_number, if_->expr_3->char_number);

        // Condition type Check
        if (compareTypes(expr_1Type, new TypeBool()) == false)
        {
            std::cout << "Error: wrong condition expression type: " << getNodeID(if_->expr_1) << std::endl
                      << "Expected: " << showner->show(new TypeBool()) << std::endl
                      << "But got: " << showner->show(expr_1Type) << std::endl
                      << "On the line: " << if_->line_number << std::endl;
            exit(1);
        }

        // Statements types Check
        if (compareTypes(expr_2Type, expr_3Type) == false && compareTypes(expr_3Type, expr_2Type) == false)
        {
            std::cout << "Error: different types of statements in the if statement: " << std::endl
                      << '"' << getNodeID(if_->expr_2) << "\" type is: " << showner->show(expr_2Type) << std::endl
                      << '"' << getNodeID(if_->expr_3) << "\" type is: " << showner->show(expr_3Type) << std::endl
                      << "On the line: " << if_->line_number << std::endl;
            exit(1);
        }

        if (compareTypes(expr_2Type, new TypeBottom()) == false)
        {
            expr_2Type = expr_3Type;
        }

        // Return if_ type
        this->setLastReturn(expr_2Type);
    }

    void VisitTypeCheck::visitLet(Let *let)
    {
        /* Code For Let Goes Here */

        if (let->listpatternbinding_)
            let->listpatternbinding_->accept(this);
        if (let->expr_)
            let->expr_->accept(this);
    }

    void VisitTypeCheck::visitLetRec(LetRec *let_rec)
    {
        /* Code For LetRec Goes Here */

        if (let_rec->listpatternbinding_)
            let_rec->listpatternbinding_->accept(this);
        if (let_rec->expr_)
            let_rec->expr_->accept(this);
    }

    void VisitTypeCheck::visitLessThan(LessThan *less_than)
    {
        /* Code For LessThan Goes Here */

        if (less_than->expr_1)
            less_than->expr_1->accept(this);
        Type *expr_1Type = this->getLastReturn();

        if (less_than->expr_2)
            less_than->expr_2->accept(this);
        Type *expr_2Type = this->getLastReturn();

        if (compareTypes(expr_1Type, expr_2Type) == false && compareTypes(expr_2Type, expr_1Type) == false)
        {
            std::cout << "Error: different types in the if condition: " << std::endl
                      << getNodeID(less_than->expr_1) << std::endl
                      << getNodeID(less_than->expr_2) << std::endl
                      << "On the line: " << less_than->line_number << std::endl;
            exit(1);
        }

        this->setLastReturn(new TypeBool());
    }

    void VisitTypeCheck::visitLessThanOrEqual(LessThanOrEqual *less_than_or_equal)
    {
        /* Code For LessThanOrEqual Goes Here */

        if (less_than_or_equal->expr_1)
            less_than_or_equal->expr_1->accept(this);
        Type *expr_1Type = this->getLastReturn();

        if (less_than_or_equal->expr_2)
            less_than_or_equal->expr_2->accept(this);
        Type *expr_2Type = this->getLastReturn();

        if (compareTypes(expr_1Type, expr_2Type) == false && compareTypes(expr_2Type, expr_1Type) == false)
        {
            std::cout << "Error: different types in the if condition: " << std::endl
                      << getNodeID(less_than_or_equal->expr_1) << std::endl
                      << getNodeID(less_than_or_equal->expr_2) << std::endl
                      << "On the line: " << less_than_or_equal->line_number << std::endl;
            exit(1);
        }

        this->setLastReturn(new TypeBool());
    }

    void VisitTypeCheck::visitGreaterThan(GreaterThan *greater_than)
    {
        /* Code For GreaterThan Goes Here */

        if (greater_than->expr_1)
            greater_than->expr_1->accept(this);
        Type *expr_1Type = this->getLastReturn();

        if (greater_than->expr_2)
            greater_than->expr_2->accept(this);
        Type *expr_2Type = this->getLastReturn();

        if (compareTypes(expr_1Type, expr_2Type) == false && compareTypes(expr_2Type, expr_1Type) == false)
        {
            std::cout << "Error: different types in the if condition: " << std::endl
                      << getNodeID(greater_than->expr_1) << std::endl
                      << getNodeID(greater_than->expr_2) << std::endl
                      << "On the line: " << greater_than->line_number << std::endl;
            exit(1);
        }

        this->setLastReturn(new TypeBool());
    }

    void VisitTypeCheck::visitGreaterThanOrEqual(GreaterThanOrEqual *greater_than_or_equal)
    {
        /* Code For GreaterThanOrEqual Goes Here */

        if (greater_than_or_equal->expr_1)
            greater_than_or_equal->expr_1->accept(this);
        Type *expr_1Type = this->getLastReturn();

        if (greater_than_or_equal->expr_2)
            greater_than_or_equal->expr_2->accept(this);
        Type *expr_2Type = this->getLastReturn();

        if (compareTypes(expr_1Type, expr_2Type) == false && compareTypes(expr_2Type, expr_1Type) == false)
        {
            std::cout << "Error: different types in the if condition: " << std::endl
                      << getNodeID(greater_than_or_equal->expr_1) << std::endl
                      << getNodeID(greater_than_or_equal->expr_2) << std::endl
                      << "On the line: " << greater_than_or_equal->line_number << std::endl;
            exit(1);
        }

        this->setLastReturn(new TypeBool());
    }

    void VisitTypeCheck::visitEqual(Equal *equal)
    {
        /* Code For Equal Goes Here */

        if (equal->expr_1)
            equal->expr_1->accept(this);
        Type *expr_1Type = this->getLastReturn();

        if (equal->expr_2)
            equal->expr_2->accept(this);
        Type *expr_2Type = this->getLastReturn();

        if (compareTypes(expr_1Type, expr_2Type) == false && compareTypes(expr_2Type, expr_1Type) == false)
        {
            std::cout << "Error: different types in the if condition: " << std::endl
                      << getNodeID(equal->expr_1) << std::endl
                      << getNodeID(equal->expr_2) << std::endl
                      << "On the line: " << equal->line_number << std::endl;
            exit(1);
        }

        this->setLastReturn(new TypeBool());
    }

    void VisitTypeCheck::visitNotEqual(NotEqual *not_equal)
    {
        /* Code For NotEqual Goes Here */

        if (not_equal->expr_1)
            not_equal->expr_1->accept(this);
        Type *expr_1Type = this->getLastReturn();

        if (not_equal->expr_2)
            not_equal->expr_2->accept(this);
        Type *expr_2Type = this->getLastReturn();

        if (compareTypes(expr_1Type, expr_2Type) == false && compareTypes(expr_2Type, expr_1Type) == false)
        {
            std::cout << "Error: different types in the if condition: " << std::endl
                      << getNodeID(not_equal->expr_1) << std::endl
                      << getNodeID(not_equal->expr_2) << std::endl
                      << "On the line: " << not_equal->line_number << std::endl;
            exit(1);
        }

        this->setLastReturn(new TypeBool());
    }

    void VisitTypeCheck::visitTypeAsc(TypeAsc *type_asc)
    {
        /* Code For TypeAsc Goes Here */

        if (type_asc->expr_)
            type_asc->expr_->accept(this);
        if (type_asc->type_)
            type_asc->type_->accept(this);
    }

    void VisitTypeCheck::visitTypeCast(TypeCast *type_cast)
    {
        /* Code For TypeCast Goes Here */

        if (type_cast->expr_)
            type_cast->expr_->accept(this);
        if (type_cast->type_)
            type_cast->type_->accept(this);
    }

    void VisitTypeCheck::visitAbstraction(Abstraction *abstraction)
    {
        // Scope realisation
        std::unordered_map<std::string, VariableDescriptions> declearedVariablesCopy;
        declearedVariablesCopy.insert(this->declearedVariables.begin(), this->declearedVariables.end());

        // Collecting parameter types
        if (abstraction->listparamdecl_)
            abstraction->listparamdecl_->accept(this);
        std::vector<Type *> listparamdeclCopy = this->getReturnTypesList();

        if (abstraction->expr_)
            abstraction->expr_->accept(this);
        Type *expr_Type = this->getLastReturn();

        // Check if the return expression is correctly handled
        nullptrCheck(expr_Type, abstraction->expr_->line_number, abstraction->expr_->char_number);

        TypeFun *FunctionType = CombineFun(listparamdeclCopy, expr_Type);

        // Scope realisation
        this->declearedVariables.clear();
        declearedVariables.insert(declearedVariablesCopy.begin(), declearedVariablesCopy.end());

        // Return abstraction type
        this->setLastReturn(FunctionType);
    }

    void VisitTypeCheck::visitVariant(Variant *variant)
    {
        /* Code For Variant Goes Here */

        visitStellaIdent(variant->stellaident_);
        if (variant->exprdata_)
            variant->exprdata_->accept(this);
    }

    bool checkTopLevelMatch(ListMatchCase* ListMatchCase){
        auto showner = new ShowAbsyn();
        int inr = false;
        int inl = false;
        for (ListMatchCase::iterator i = ListMatchCase->begin(); i != ListMatchCase->end(); ++i)
        {
            AMatchCase * AMC = (AMatchCase *)*i;
            std::string AMCStr = showner->show(AMC->pattern_);
            if (AMCStr.size() > 11 && AMCStr.substr(0, 11) == "(PatternInr"){
                inr = true;
            }
            if (AMCStr.size() > 11 && AMCStr.substr(0, 11) == "(PatternInl"){
                inl = true;
            }
        }
        return (inr != inl);
    }

    void VisitTypeCheck::visitMatch(Match *match)
    {
        /* Code For Match Goes Here */
        if (match->expr_)
            match->expr_->accept(this);
        Type *expr_Type = this->getLastReturn();

        this->setInType(expr_Type);
        if (match->listmatchcase_)
            match->listmatchcase_->accept(this);
        std::vector<Type *> casesList = this->getReturnTypesList();
        this->removeInType();

        nullptrCheck(expr_Type, match->expr_->line_number, match->expr_->char_number);

        if (casesList.size() == 0 || checkTopLevelMatch(match->listmatchcase_))
        {
            std::cout << "Error: not enough cases in the match" << std::endl
                      << "On the line: " << match->line_number << std::endl;
            exit(1);
        }

        for (int i = 1; i < casesList.size(); ++i)
        {
            if (compareTypes(casesList[i - 1], casesList[i]) == false && compareTypes(casesList[i], casesList[i - 1]) == false)
            {
                std::cout << "Error: different match types in match expression" << std::endl
                          << "On the line: " << match->line_number << std::endl;
                exit(1);
            }
        }

        this->setLastReturn(casesList[0]);
    }

    void VisitTypeCheck::visitList(List *list)
    {
        /* Code For List Goes Here */

        if (list->listexpr_)
            list->listexpr_->accept(this);
    }

    void VisitTypeCheck::visitAdd(Add *add)
    {
        /* Code For Add Goes Here */

        if (add->expr_1)
            add->expr_1->accept(this);
        if (add->expr_2)
            add->expr_2->accept(this);
    }

    void VisitTypeCheck::visitSubtract(Subtract *subtract)
    {
        /* Code For Subtract Goes Here */

        if (subtract->expr_1)
            subtract->expr_1->accept(this);
        if (subtract->expr_2)
            subtract->expr_2->accept(this);
    }

    void VisitTypeCheck::visitLogicOr(LogicOr *logic_or)
    {
        /* Code For LogicOr Goes Here */

        if (logic_or->expr_1)
            logic_or->expr_1->accept(this);
        if (logic_or->expr_2)
            logic_or->expr_2->accept(this);
    }

    void VisitTypeCheck::visitMultiply(Multiply *multiply)
    {
        /* Code For Multiply Goes Here */

        if (multiply->expr_1)
            multiply->expr_1->accept(this);
        if (multiply->expr_2)
            multiply->expr_2->accept(this);
    }

    void VisitTypeCheck::visitDivide(Divide *divide)
    {
        /* Code For Divide Goes Here */

        if (divide->expr_1)
            divide->expr_1->accept(this);
        if (divide->expr_2)
            divide->expr_2->accept(this);
    }

    void VisitTypeCheck::visitLogicAnd(LogicAnd *logic_and)
    {
        /* Code For LogicAnd Goes Here */

        if (logic_and->expr_1)
            logic_and->expr_1->accept(this);
        if (logic_and->expr_2)
            logic_and->expr_2->accept(this);
    }

    void VisitTypeCheck::visitApplication(Application *application)
    {
        /* Code For Application Goes Here */
        if (application->expr_)
            application->expr_->accept(this);
        Type *expr_Type = this->getLastReturn();

        // Check if the function name is correctly handled
        nullptrCheck(expr_Type, application->expr_->line_number, application->expr_->char_number);

        // Check if user is not trying to assign parameters to non-function variable
        if (ifTypeFun(expr_Type) == false)
        {
            std::cout << "Error: trying to use non-function in the function call:" << std::endl
                      << "Name: " << getNodeID(application->expr_) << std::endl
                      << "Actual struct: " << showner->show(expr_Type) << std::endl
                      << "On the line: " << application->expr_->line_number << std::endl;
            exit(1);
        }

        TypeFun *expr_TypeFun = (TypeFun *)expr_Type;

        if (application->listexpr_)
            application->listexpr_->accept(this);
        std::vector<Type *> listexpr_Copy = this->getReturnTypesList();

        std::vector<Type *> Arguments;
        for (ListType::iterator i = expr_TypeFun->listtype_->begin(); i != expr_TypeFun->listtype_->end(); ++i)
            Arguments.push_back(*i);

        // Number of function arguments is less then number of passing parameters
        if (Arguments.size() < listexpr_Copy.size())
        {
            std::cout << "Error: to much parameters in the function call" << std::endl
                      << "Name: " << getNodeID(application->expr_) << std::endl
                      << "On the line: " << application->expr_->line_number << std::endl;
            exit(1);
        }
        // Number of function arguments is greater then number of passing parameters
        if (Arguments.size() > listexpr_Copy.size())
        {
            std::cout << "Error: not enaught parameters for the function" << std::endl
                      << "Name: " << getNodeID(application->expr_) << std::endl
                      << "On the line: " << application->expr_->line_number << std::endl;
            exit(1);
        }

        // Comparing types of arguments and passing parameters
        for (int i = 0; i < Arguments.size() && i < listexpr_Copy.size(); ++i)
        {
            if (compareTypes(listexpr_Copy[i], Arguments[i]) == false)
            {
                std::cout << "Error: incorrect parameters in the function call" << std::endl;
                std::cout << "Function name: " << getNodeID(application->expr_) << std::endl
                          << "Expected: " << showner->show(Arguments[i]) << std::endl;
                exit(1);
            }
        }

        // Return application return type
        this->setLastReturn(expr_TypeFun->type_);
    }

    void VisitTypeCheck::visitDotRecord(DotRecord *dot_record)
    {
        /* Code For DotRecord Goes Here */

        if (dot_record->expr_)
            dot_record->expr_->accept(this);
        TypeRecord *returnRecord = (TypeRecord *)this->getLastReturn();

        if (returnRecord == nullptr || returnRecord->listrecordfieldtype_ == nullptr)
        {
            std::cout << "Error: no tuple in dot tuple call: " << std::endl
                      << "On the line" << dot_record->expr_->line_number << std::endl;
            exit(1);
        }

        visitStellaIdent(dot_record->stellaident_);

        Type *constructType = nullptr;
        for (ListRecordFieldType::iterator i = returnRecord->listrecordfieldtype_->begin(); i != returnRecord->listrecordfieldtype_->end(); ++i)
        {
            ARecordFieldType *ARFT = (ARecordFieldType *)(*i);
            if (ARFT->stellaident_ == dot_record->stellaident_)
            {
                constructType = ARFT->type_;
            }
        }

        if (constructType == nullptr)
        {
            std::cout << "Error: incorrect record field name" << std::endl
                      << "On the line: " << dot_record->line_number << std::endl
                      << "Character number: " << dot_record->char_number << std::endl;
            exit(1);
        }

        this->setLastReturn(constructType);
    }

    void VisitTypeCheck::visitDotTuple(DotTuple *dot_tuple)
    {
        /* Code For DotTuple Goes Here */

        if (dot_tuple->expr_)
            dot_tuple->expr_->accept(this);

        TypeTuple *returnTuple = (TypeTuple *)this->getLastReturn();

        if (returnTuple == nullptr || returnTuple->listtype_ == nullptr)
        {
            std::cout << "Error: no tuple in dot tuple call: " << std::endl
                      << "On the line" << dot_tuple->expr_->line_number << std::endl;
            exit(1);
        }
        std::vector<Type *> tupleList;
        for (ListType::iterator i = returnTuple->listtype_->begin(); i != returnTuple->listtype_->end(); ++i)
        {
            tupleList.push_back(*i);
        }

        visitInteger(dot_tuple->integer_);

        if (dot_tuple->integer_ > tupleList.size())
        {
            std::cout << "Error: unexpected access to component number " << dot_tuple->integer_ << std::endl
                      << "On the line: " << dot_tuple->line_number << std::endl
                      << "Character number: " << dot_tuple->char_number << std::endl;
            exit(1);
        }

        this->setLastReturn(tupleList[dot_tuple->integer_ - 1]);
    }

    void VisitTypeCheck::visitTuple(Tuple *tuple)
    {
        /* Code For Tuple Goes Here */

        if (tuple->listexpr_)
            tuple->listexpr_->accept(this);

        std::vector<Type *> listparamdeclCopy = this->getReturnTypesList();

        TypeTuple *TupleType = CombineTuple(listparamdeclCopy);

        this->setLastReturn(TupleType);
    }

    void VisitTypeCheck::visitRecord(Record *record)
    {
        /* Code For Record Goes Here */

        if (record->listbinding_)
            record->listbinding_->accept(this);
        // Дописать сборщик типов
        std::vector<Type *> listbindingCopy = this->getReturnTypesList();

        ListRecordFieldType *returnTypeList = new ListRecordFieldType();

        int j = listbindingCopy.size() - 1;
        for (ListBinding::iterator i = record->listbinding_->end() - 1; i != record->listbinding_->begin() - 1; --i, --j)
        {
            ABinding *AB = (ABinding *)(*i);
            returnTypeList = consListRecordFieldType(new ARecordFieldType(AB->stellaident_, listbindingCopy[j]), returnTypeList);
        }

        TypeRecord *returnType = new TypeRecord(returnTypeList);

        this->setLastReturn(returnType);
    }

    void VisitTypeCheck::visitConsList(ConsList *cons_list)
    {
        /* Code For ConsList Goes Here */

        if (cons_list->expr_1)
            cons_list->expr_1->accept(this);
        if (cons_list->expr_2)
            cons_list->expr_2->accept(this);
    }

    void VisitTypeCheck::visitHead(Head *head)
    {
        /* Code For Head Goes Here */

        if (head->expr_)
            head->expr_->accept(this);
    }

    void VisitTypeCheck::visitIsEmpty(IsEmpty *is_empty)
    {
        /* Code For IsEmpty Goes Here */

        if (is_empty->expr_)
            is_empty->expr_->accept(this);
    }

    void VisitTypeCheck::visitTail(Tail *tail)
    {
        /* Code For Tail Goes Here */

        if (tail->expr_)
            tail->expr_->accept(this);
    }

    void VisitTypeCheck::visitInl(Inl *inl)
    {
        /* Code For Inl Goes Here */

        if (inl->expr_)
            inl->expr_->accept(this);
        Type *expt_Type = this->getLastReturn();

        TypeSum *output = new TypeSum(expt_Type, new TypeBottom());

        this->setLastReturn(output);
    }

    void VisitTypeCheck::visitInr(Inr *inr)
    {
        /* Code For Inr Goes Here */
        if (inr->expr_)
            inr->expr_->accept(this);
        Type *expt_Type = this->getLastReturn();

        TypeSum *output = new TypeSum(new TypeBottom(), expt_Type);

        this->setLastReturn(output);
    }

    void VisitTypeCheck::visitSucc(Succ *succ)
    {
        /* Code For Succ Goes Here */

        if (succ->expr_)
            succ->expr_->accept(this);
        Type *expr_Type = this->getLastReturn();

        // Check if succ parameter is correctly handled
        nullptrCheck(expr_Type, succ->expr_->line_number, succ->expr_->char_number);

        // Check if succ parameter is correctly typed
        if (compareTypes(expr_Type, new TypeNat()) == false)
        {
            std::cout << "Error: incorrect type of succ argument: " << getNodeID(succ->expr_) << std::endl;
            exit(1);
        }

        // Return succ type
        this->setLastReturn(new TypeNat());
    }

    void VisitTypeCheck::visitLogicNot(LogicNot *logic_not)
    {
        /* Code For LogicNot Goes Here */

        if (logic_not->expr_)
            logic_not->expr_->accept(this);
    }

    void VisitTypeCheck::visitPred(Pred *pred)
    {
        /* Code For Pred Goes Here */

        if (pred->expr_)
            pred->expr_->accept(this);
    }

    void VisitTypeCheck::visitIsZero(IsZero *is_zero)
    {
        /* Code For IsZero Goes Here */

        if (is_zero->expr_)
            is_zero->expr_->accept(this);
    }

    void VisitTypeCheck::visitFix(Fix *fix)
    {
        /* Code For Fix Goes Here */

        if (fix->expr_)
            fix->expr_->accept(this);
    }

    void VisitTypeCheck::visitNatRec(NatRec *nat_rec)
    {
        /* Code For NatRec Goes Here */

        if (nat_rec->expr_1)
            nat_rec->expr_1->accept(this);
        Type *expr_1Type = this->getLastReturn();

        if (nat_rec->expr_2)
            nat_rec->expr_2->accept(this);
        Type *expr_2Type = this->getLastReturn();

        if (nat_rec->expr_3)
            nat_rec->expr_3->accept(this);
        Type *expr_3Type = this->getLastReturn();

        // Check if parameters is handled correctly
        nullptrCheck(expr_1Type, nat_rec->expr_1->line_number, nat_rec->expr_1->char_number);
        nullptrCheck(expr_2Type, nat_rec->expr_2->line_number, nat_rec->expr_2->char_number);
        nullptrCheck(expr_3Type, nat_rec->expr_3->line_number, nat_rec->expr_3->char_number);

        // Check the first parameter if correctly typed
        if (compareTypes(expr_1Type, new TypeNat()) == false)
        {
            std::cout << "Error: wrong type of the first argument for Nar::rec " << std::endl
                      << "Name: " << getNodeID(nat_rec->expr_1) << std::endl
                      << "Type: " << showner->show(expr_1Type) << std::endl
                      << "On the line: " << nat_rec->expr_1->line_number << std::endl;
            exit(1);
        }

        // Check if the third parameter if correctly typed
        if (ifTypeFun(expr_3Type) == false)
        {
            std::cout << "Error: wrong type of the third argument for Nar::rec " << std::endl
                      << "Expected: fn(Nat) -> (fn(T) -> T)" << std::endl
                      << "Name: " << getNodeID(nat_rec->expr_3) << std::endl
                      << "Type: " << showner->show(expr_3Type) << std::endl
                      << "On the line: " << nat_rec->expr_3->line_number << std::endl;
            exit(1);
        }

        // Check the third parameter
        TypeFun *expr_3TypeFun = (TypeFun *)expr_3Type;
        std::vector<Type *> expr_3Parameters;
        for (ListType::iterator i = expr_3TypeFun->listtype_->begin(); i != expr_3TypeFun->listtype_->end(); ++i)
            expr_3Parameters.push_back(*i);

        if (expr_3Parameters.size() > 1)
        {
            std::cout << "Error: too much parameters in the function call" << std::endl
                      << "Name: " << getNodeID(nat_rec->expr_3) << std::endl
                      << "Type: " << showner->show(expr_3Type) << std::endl
                      << "On the line: " << nat_rec->expr_3->line_number << std::endl;
            exit(1);
        }
        if (compareTypes(expr_3Parameters[0], new TypeNat()) == false)
        {
            std::cout << "Error: wrong type of the third argument"
                      << "Expected: fn(**Nat**) -> (fn(T) -> T)" << std::endl
                      << "Name: " << getNodeID(nat_rec->expr_3) << std::endl
                      << "Type: " << showner->show(expr_3Type) << std::endl
                      << "On the line: " << nat_rec->expr_3->line_number << std::endl;
            exit(1);
        }

        // Check the third parameter return type
        if (ifTypeFun(expr_3TypeFun->type_) == false)
        {
            std::cout << "Error: wrong type of the third argument for Nar::rec " << std::endl
                      << "Expected: fn(Nat) -> **(fn(T) -> T)**" << std::endl
                      << "Name: " << getNodeID(nat_rec->expr_3) << std::endl
                      << "Type: " << showner->show(expr_3Type) << std::endl
                      << "On the line: " << nat_rec->expr_3->line_number << std::endl;
            exit(1);
        }

        TypeFun *expr_3ReturnType = (TypeFun *)expr_3TypeFun->type_;

        std::vector<Type *> expr_3RetFuncParameters;
        for (ListType::iterator i = expr_3ReturnType->listtype_->begin(); i != expr_3ReturnType->listtype_->end(); ++i)
            expr_3RetFuncParameters.push_back(*i);

        if (expr_3RetFuncParameters.size() > 1)
        {
            std::cout << "Error: too much parameters in the function" << std::endl
                      << "Expected: fn(Nat) -> (fn(**T**) -> T)" << std::endl
                      << "Name: " << getNodeID(nat_rec->expr_3) << std::endl
                      << "Type: " << showner->show(expr_3Type) << std::endl
                      << "On the line: " << nat_rec->expr_3->line_number << std::endl;
            exit(1);
        }
        if (compareTypes(expr_3RetFuncParameters[0], expr_3ReturnType->type_) == false &&
            compareTypes(expr_3ReturnType->type_, expr_3RetFuncParameters[0]) == false)
        {
            std::cout << "Error: different types in the third argument of the Nat::rec function: " << std::endl
                      << "Expected: fn(Nat) -> (fn(**T**) -> **T**)" << std::endl
                      << "Name: " << getNodeID(nat_rec->expr_3) << std::endl
                      << "Type: " << showner->show(expr_3Type) << std::endl
                      << "On the line: " << nat_rec->expr_3->line_number << std::endl;
            exit(1);
        }

        // Check The third parameter return type and the second parameter
        if (compareTypes(expr_3ReturnType->type_, expr_2Type) == false &&
            compareTypes(expr_2Type, expr_3ReturnType->type_) == false)
        {
            std::cout << "Error: different types of statements in the third arg and the second one: " << std::endl
                      << "Expected: Nat::rec(Nat, T, fn(Nat) -> (fn(T) -> T))" << std::endl
                      << "Second parameter name: " << getNodeID(nat_rec->expr_2) << std::endl
                      << "Second parameter type: " << showner->show(expr_2Type) << std::endl
                      << "Third parameter name: " << getNodeID(nat_rec->expr_3) << std::endl
                      << "Third parameter **T** type: " << showner->show(expr_3ReturnType->type_) << std::endl
                      << "On the line: " << nat_rec->expr_2->line_number << std::endl;
            exit(1);
        }

        // Return nat::rec type
        this->setLastReturn(expr_2Type);
    }

    void VisitTypeCheck::visitFold(Fold *fold)
    {
        /* Code For Fold Goes Here */

        if (fold->type_)
            fold->type_->accept(this);
        if (fold->expr_)
            fold->expr_->accept(this);
    }

    void VisitTypeCheck::visitUnfold(Unfold *unfold)
    {
        /* Code For Unfold Goes Here */

        if (unfold->type_)
            unfold->type_->accept(this);
        if (unfold->expr_)
            unfold->expr_->accept(this);
    }

    void VisitTypeCheck::visitConstTrue(ConstTrue *const_true)
    {
        /* Code For ConstTrue Goes Here */

        // Return true type
        this->setLastReturn(new TypeBool());
    }

    void VisitTypeCheck::visitConstFalse(ConstFalse *const_false)
    {
        /* Code For ConstFalse Goes Here */

        // Return false type
        this->setLastReturn(new TypeBool());
    }

    void VisitTypeCheck::visitConstUnit(ConstUnit *const_unit)
    {
        /* Code For ConstUnit Goes Here */

        this->setLastReturn(new TypeUnit());
    }

    void VisitTypeCheck::visitConstInt(ConstInt *const_int)
    {
        /* Code For ConstInt Goes Here */
        if (const_int->integer_ != 0)
        {
            std::cout << "Error: invalid constant integer. In the Stella languagne only 0 is valid constInt" << std::endl
                      << "On the line: " << const_int->line_number << std::endl;
            exit(1);
        }

        visitInteger(const_int->integer_);

        // Return integer type
        this->lastReturn = new TypeNat();
    }

    void VisitTypeCheck::visitConstMemory(ConstMemory *const_memory)
    {
        /* Code For ConstMemory Goes Here */

        visitMemoryAddress(const_memory->memoryaddress_);
    }

    void VisitTypeCheck::visitVar(Var *var)
    {
        /* Code For Var Goes Here */

        ifDefined(var->stellaident_, var->line_number);

        visitStellaIdent(var->stellaident_);

        // Return variable type
        this->setLastReturn(this->declearedVariables[var->stellaident_].type);
    }

    void VisitTypeCheck::visitAPatternBinding(APatternBinding *a_pattern_binding)
    {
        /* Code For APatternBinding Goes Here */

        if (a_pattern_binding->pattern_)
            a_pattern_binding->pattern_->accept(this);
        if (a_pattern_binding->expr_)
            a_pattern_binding->expr_->accept(this);
    }

    void VisitTypeCheck::visitAVariantFieldType(AVariantFieldType *a_variant_field_type)
    {
        /* Code For AVariantFieldType Goes Here */

        visitStellaIdent(a_variant_field_type->stellaident_);
        if (a_variant_field_type->optionaltyping_)
            a_variant_field_type->optionaltyping_->accept(this);
    }

    void VisitTypeCheck::visitARecordFieldType(ARecordFieldType *a_record_field_type)
    {
        /* Code For ARecordFieldType Goes Here */

        visitStellaIdent(a_record_field_type->stellaident_);
        if (a_record_field_type->type_)
            a_record_field_type->type_->accept(this);
        Type *field_Type = this->getLastReturn();

        // Check if type for RecordFieldType is correctly handled
        nullptrCheck(field_Type, a_record_field_type->type_->line_number, a_record_field_type->type_->char_number);
    }

    void VisitTypeCheck::visitATyping(ATyping *a_typing)
    {
        /* Code For ATyping Goes Here */

        if (a_typing->expr_)
            a_typing->expr_->accept(this);
        if (a_typing->type_)
            a_typing->type_->accept(this);
    }

    void VisitTypeCheck::visitListStellaIdent(ListStellaIdent *list_stella_ident)
    {
        for (ListStellaIdent::iterator i = list_stella_ident->begin(); i != list_stella_ident->end(); ++i)
        {
            visitStellaIdent(*i);
        }
    }

    void VisitTypeCheck::visitListExtensionName(ListExtensionName *list_extension_name)
    {
        for (ListExtensionName::iterator i = list_extension_name->begin(); i != list_extension_name->end(); ++i)
        {
            visitExtensionName(*i);
        }
    }

    void VisitTypeCheck::visitListExtension(ListExtension *list_extension)
    {
        for (ListExtension::iterator i = list_extension->begin(); i != list_extension->end(); ++i)
        {
            (*i)->accept(this);
        }
    }

    void VisitTypeCheck::visitListDecl(ListDecl *list_decl)
    {
        for (ListDecl::iterator i = list_decl->begin(); i != list_decl->end(); ++i)
        {
            (*i)->accept(this);
        }
    }

    void VisitTypeCheck::visitListLocalDecl(ListLocalDecl *list_local_decl)
    {
        for (ListLocalDecl::iterator i = list_local_decl->begin(); i != list_local_decl->end(); ++i)
        {
            (*i)->accept(this);
        }
    }

    void VisitTypeCheck::visitListAnnotation(ListAnnotation *list_annotation)
    {
        for (ListAnnotation::iterator i = list_annotation->begin(); i != list_annotation->end(); ++i)
        {
            (*i)->accept(this);
        }
    }

    void VisitTypeCheck::visitListParamDecl(ListParamDecl *list_param_decl)
    {
        // Collecting Parameter types
        std::vector<Type *> ParamCollector;
        for (ListParamDecl::iterator i = list_param_decl->begin(); i != list_param_decl->end(); ++i)
        {
            (*i)->accept(this);
            Type *temp = this->getLastReturn();
            ParamCollector.push_back(temp);
        }

        this->setReturnTypesList(ParamCollector);
    }

    void VisitTypeCheck::visitListType(ListType *list_type)
    {
        // Collecting types
        std::vector<Type *> TypeCollector;
        for (ListType::iterator i = list_type->begin(); i != list_type->end(); ++i)
        {
            (*i)->accept(this);
            Type *temp = this->getLastReturn();
            TypeCollector.push_back(temp);
        }
        this->setReturnTypesList(TypeCollector);
    }

    void VisitTypeCheck::visitListMatchCase(ListMatchCase *list_match_case)
    {
        // Collecting types
        std::vector<Type *> TypeCollector;
        Type *input = getInType();
        for (ListMatchCase::iterator i = list_match_case->begin(); i != list_match_case->end(); ++i)
        {
            this->setInType(input);
            (*i)->accept(this);
            this->removeInType();
            Type *temp = this->getLastReturn();
            TypeCollector.push_back(temp);
        }
        this->setReturnTypesList(TypeCollector);
    }

    void VisitTypeCheck::visitListPattern(ListPattern *list_pattern)
    {
        TypeTuple *input = (TypeTuple *)this->getInType();

        ListType::iterator j = input->listtype_->begin();
        for (ListPattern::iterator i = list_pattern->begin(); i != list_pattern->end() && j != input->listtype_->end(); ++i, ++j)
        {
            this->setInType((*j));
            (*i)->accept(this);
        }
    }

    void VisitTypeCheck::visitListLabelledPattern(ListLabelledPattern *list_labelled_pattern)
    {
        // Collecting types
        TypeRecord *input = (TypeRecord *)this->getInType();

        ListRecordFieldType::iterator j = input->listrecordfieldtype_->begin();
        for (ListLabelledPattern::iterator i = list_labelled_pattern->begin();
             i != list_labelled_pattern->end() && j != input->listrecordfieldtype_->end(); ++i, ++j)
        {
            ARecordFieldType *ARFT = (ARecordFieldType *)(*j);
            ALabelledPattern *ALP = (ALabelledPattern *)(*i);
            if (ARFT->stellaident_ != ALP->stellaident_)
            {
                std::cout << "Error: incorrect name in the pattern record" << std::endl
                          << "Expected: " << ARFT->stellaident_ << std::endl
                          << "But got: " << ALP->stellaident_ << std::endl;
            }

            this->setInType(ARFT->type_);
            (*i)->accept(this);
        }
    }

    void VisitTypeCheck::visitListBinding(ListBinding *list_binding)
    {
        // Collecting types
        std::vector<Type *> TypeCollector;
        for (ListBinding::iterator i = list_binding->begin(); i != list_binding->end(); ++i)
        {
            (*i)->accept(this);
            Type *temp = this->getLastReturn();
            TypeCollector.push_back(temp);
        }
        this->setReturnTypesList(TypeCollector);
    }

    void VisitTypeCheck::visitListExpr(ListExpr *list_expr)
    {
        // Collecting expression types
        std::vector<Type *> ExprCollector;
        for (ListExpr::iterator i = list_expr->begin(); i != list_expr->end(); ++i)
        {
            (*i)->accept(this);
            Type *temp = this->getLastReturn();
            ExprCollector.push_back(temp);
        }
        this->setReturnTypesList(ExprCollector);
    }

    void VisitTypeCheck::visitListPatternBinding(ListPatternBinding *list_pattern_binding)
    {
        for (ListPatternBinding::iterator i = list_pattern_binding->begin(); i != list_pattern_binding->end(); ++i)
        {
            (*i)->accept(this);
        }
    }

    void VisitTypeCheck::visitListVariantFieldType(ListVariantFieldType *list_variant_field_type)
    {
        for (ListVariantFieldType::iterator i = list_variant_field_type->begin(); i != list_variant_field_type->end(); ++i)
        {
            (*i)->accept(this);
        }
    }

    void VisitTypeCheck::visitListRecordFieldType(ListRecordFieldType *list_record_field_type)
    {
        for (ListRecordFieldType::iterator i = list_record_field_type->begin(); i != list_record_field_type->end(); ++i)
        {
            (*i)->accept(this);
        }
    }

    void VisitTypeCheck::visitInteger(Integer x)
    {
        /* Code for Integer Goes Here */
    }

    void VisitTypeCheck::visitChar(Char x)
    {
        /* Code for Char Goes Here */
    }

    void VisitTypeCheck::visitDouble(Double x)
    {
        /* Code for Double Goes Here */
    }

    void VisitTypeCheck::visitString(String x)
    {
        /* Code for String Goes Here */
    }

    void VisitTypeCheck::visitIdent(Ident x)
    {
        /* Code for Ident Goes Here */
    }

    void VisitTypeCheck::visitStellaIdent(StellaIdent x)
    {
        /* Code for StellaIdent Goes Here */
    }

    void VisitTypeCheck::visitExtensionName(ExtensionName x)
    {
        /* Code for ExtensionName Goes Here */
    }

    void VisitTypeCheck::visitMemoryAddress(MemoryAddress x)
    {
        /* Code for MemoryAddress Goes Here */
    }

}
