#include "global.h"

char lexbuf[BSIZE];
int lineno = 1;
int tokenval = NONE;

int lexan() 
{
    int t;
    while(1) 
    {
        t = getchar();
        if(t == ' ' || t == '\t')
            continue;
        else if(t == '\n')
            lineno++;
        else if (isdigit(t))
        {
            ungetc(t,stdin);
            scanf("%d", &tokenval);
            return NUM;
        }
        else if (isalpha(t)) 
        {
            int p, b = 0;
            while(isalnum(t))
            {
                lexbuf[b] = t;
                t = getchar();
                b++;
                if(b >= BSIZE)
                {
                    error("compiler error");
                }
            }
            lexbuf[b] = EOS;
            if(t != EOF)
                ungetc(t,stdin);
            p = lookup(lexbuf);
            if(p == 0)
                p = insert(lexbuf,ID);
            tokenval = p;
            return symtable[p].token;
        }
        else if(t == EOF)
            return DONE;
        else 
        {
            // e.g '+', '-'
            tokenval = NONE;
            return t;
        }
    }
}