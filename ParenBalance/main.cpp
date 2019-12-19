/*
 * Compile with: 
 * 		g++ -std=c++11 main.cpp -o paren
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cassert>

typedef unsigned int u32; 
typedef int s32;
typedef char s8;

namespace tf
{
    struct Stack
    {
        u32 _top;
        u32 _capacity;
        s8* _data;
    };

    void Stack_Create(Stack* s, u32 size)
    {
        assert(s != nullptr && "[Stack_Create] stack is null");
        s->_data = (s8*) malloc(size * sizeof(s8));
        s->_top = 0;
        s->_capacity = size;
    }

    void Stack_Push(Stack* s, s8 element)
    {
        assert(s != nullptr && "[Stack_Push] stack is null");
        assert(s->_top < s->_capacity && "[Stack_Push] stack is full");

        s->_data[s->_top++] = element;
    }

    void Stack_Pop(Stack* s, s8* oElement)
    {
        assert(s != nullptr && "[Stack_Push] stack is null");
        assert(s->_top > 0 && "[Stack_Push] stack is empty");

		if(oElement == nullptr)
		{
			s->_top--;
			return;
		}

        *oElement = s->_data[--s->_top];
    }

    void Stack_Destroy(Stack* s)
    {
        assert(s != nullptr && "[Stack_Destroy] stack is null");
        free((void*) s->_data);
        s->_top = 0;
        s->_capacity = 0;
    }

    void Stack_Top(Stack* s, s8* oTopElement)
    {
        assert(s != nullptr && "[Stack_Top] stack is null");
        assert(s->_top > 0 && "[Stack_Top] stack is empty");

		if(oTopElement == nullptr)
			return;

        *oTopElement = s->_data[s->_top - 1];
    }

	u32 Stack_Empty(Stack* s)
	{
		if(s->_top <= 0)
			return 1;
		return 0;
	}
}

u32 CheckParenBalance(const s8* str)
{
	using namespace tf;
    s8 ch;
    u32 i = 0;
    Stack s;
    Stack_Create(&s, strlen(str));

    while((ch = str[i++]) != '\0')
	{
		switch(ch)
		{
		case '(':
		case '{':
		case '[':
            Stack_Push(&s, ch);
			break;

		case ')':
		{
			s8 top;
			if(Stack_Empty(&s))
				return 0;
			Stack_Top(&s, &top);
			if(top == '(')
				Stack_Pop(&s, nullptr); //correct braces
			else
				return 0;
			break;
		}

		case '}':
		{
			s8 top;
			if(Stack_Empty(&s))
				return 0;
			Stack_Top(&s, &top);
			if(top == '{')
				Stack_Pop(&s, nullptr); //correct braces
			else
				return 0;
			break;
		}

		case ']':
		{
			s8 top;
			if(Stack_Empty(&s))
				return 0;
			Stack_Top(&s, &top);
			if(top == '[')
				Stack_Pop(&s, nullptr); //correct braces
			else
				return 0;
			break;
		}

		default: //do nothing
			;
		}
	}

	if(Stack_Empty(&s))
		return 1;
	return 0;
}

int main()
{
	#define NUM_CASES 10
	const s8* exp[NUM_CASES] = 
	{
		"{}",
		"{)",
		"[}]",
		"{{{{{]]]]",
		"({})",
		"({)}",
		"whaaadaaaapp",
		"",
		"REEE",
		"(9+0)*{3*3}/200+990(220)<<<<<<<<",
	};

	for(int i = 0;i < NUM_CASES;++i)
	{
		u32 balanced = CheckParenBalance(exp[i]);
		printf("%s is %s\n", exp[i], balanced ? "balanced" : "unbalanced");
	}

	return(0);
}