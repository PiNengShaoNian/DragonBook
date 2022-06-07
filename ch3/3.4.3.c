//下标从零开始
int* failureFunction(char* str) {
    int n = strlen(str);
    int* f = (int*)malloc(sizeof(int) * n);
    memset(f, 0, sizeof(int) * n);
    for(int i = 1, j = -1; i < n; ++i) {
        while(j >= 0 && str[i] != str[j + 1]) {
            j = f[j];
        }
        if(str[i] == str[j + 1]) {
            ++j;
        }
        f[i] = j;
    }

    return f;
}