include <stdio.h>
include <err.h>


if ((p = malloc(size)) == NULL)
        err(EX_OSERR, NULL);
if ((fd = open(file_name, O_RDONLY, 0)) == -1)
        err(EX_NOINPUT, "%s", file_name);