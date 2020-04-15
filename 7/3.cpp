const char *strrchr(const char *str, int ch)
{
    char c = static_cast<char>(ch);
    const char *ptr = nullptr;
    while (*str != '\0')
    {
        if (*str == c)
            ptr = str;
        ++str;
    }
    return ptr;
}