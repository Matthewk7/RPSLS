class rpslsType
{
    public:
        rpslsType();
        void playRound();
        void showScores();
        void resetScores();
        bool playAgain();
        void getScores(int &, int &, int &) const;
    private:
        int userWins;
        int userLosses;
        int gamesPlayed;
        int getUserMove();
        int getComputerMove(); 
};