class For: public Stmt {
    Expr* E1;
    Expr* E2;
    Expr* E3;
    Stmt* S;

    public:
        For(Expr* E1, Expr* E2, Expr* E3, Stmt* S): E1(E1), E2(E2), E3(E3), S(S) {}
        void gen(int b, int a) {
            E1.gen();
            Label* start = new Label();
            Label* end = new Label();
            emit(start->name + ":");
            emit("ifFlase " + E2->rvalue() + " goto " + &end);
            S.gen();
            E3.gen();
            emit("goto " + start->name);
            emit(end->name + ":");
        }
}