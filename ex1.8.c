#include <stdio.h>

main()
{
    int c, nl, ns, nt;
    nl = 0;
    ns = 0;
    nt = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
        else if (c == ' ')
            ++ns;
        else if (c == '\t')
            ++nt;
    printf ("%d %d %d\n", nl, ns, nt);
}