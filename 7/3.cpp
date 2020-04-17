const char *strrchr(const char *str, int ch)
{
    char c = static_cast<char>(ch);
    const char *ptr = nullptr;
    for (const char *p = str; *p != '\0'; ++p)
        if (*p == c)
            ptr = p;
    return ptr;
}