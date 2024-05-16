
float str_to_float(const char *str) {
    float result = 0.0;
    int sign = 1;
    int integerPart = 0;
    float fractionPart = 0.0;
    int fractionLength = 0;
    int inFraction = 0;

    // Handle sign
    if (*str == '-') {
        sign = -1;
        str++;
    }

    // Parse integer part
    while (*str >= '0' && *str <= '9') {
        integerPart = integerPart * 10 + (*str - '0');
        str++;
    }

    // Parse fraction part
    if (*str == '.') {
        str++;
        inFraction = 1;
        while (*str >= '0' && *str <= '9') {
            fractionPart = fractionPart * 10 + (*str - '0');
            fractionLength++;
            str++;
        }
    }

    // Combine integer and fraction parts
    result = integerPart + fractionPart / pow(10, fractionLength);

    return sign * result;
}

