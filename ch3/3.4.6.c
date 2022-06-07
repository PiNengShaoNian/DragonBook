int kmp(char *str, char* sub) {
    int n = strlen(str);
    int m = strlen(sub);
    int *f = failureFunction(sub);
    int i = 0, j = 0;
    while(i < n) {
        while(j >= 0 && str[i] != sub[j + 1]) {
            j = f[j];
        }
        if(str[i] == sub[j + 1]) {
            ++j;
        }
        if(j == m - 1) {
            return i - m + 1;
        }
        ++i;
    }
    free(f);
    return -1;
}