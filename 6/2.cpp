int mystrstr(char a[], char b[])
{
    for (int i = 0; a[i] != '\0'; ++i)
        if (a[i] == b[0])
        {
            bool has_found = true;
            for (int j = 0; b[j] != '\0'; ++j)
                if (b[j] != a[i + j])
                {
                    has_found = false;
                    break;
                }
            if (has_found)
                return i;
        }
    return -1;
}