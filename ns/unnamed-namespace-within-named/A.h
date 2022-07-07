//
// Created by Abbas Gussenov on 2/23/22.
//

#ifndef UNNAMED_NAMESPACE_WITHIN_NAMED_A_H
#define UNNAMED_NAMESPACE_WITHIN_NAMED_A_H


void Bat();

void Bar();

namespace qwe
{

void Asd();

namespace
{
void Zxc();
void Aaa();  // function 'qwe::(anonymous namespace)::Aaa' has internal linkage
}

}

void Sub();

#endif //UNNAMED_NAMESPACE_WITHIN_NAMED_A_H
