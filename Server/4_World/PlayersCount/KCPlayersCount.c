/// @brief Процессор отправки сообщений о числе игроков в чат
class KCPlayersCount
{
    private ref KCPlayersCountConfig config;

    private ref KCPlayerInfo playerInfoSystem;

    private float timeCounter = 0;

    void KCPlayersCount(KCPlayerInfo playerInfo, KCPlayersCountConfig playersCountConfig)
    {
        config = playersCountConfig;
        timeCounter = config.PeriodSec;
        playerInfoSystem = playerInfo;

    }

    void OnTick(float timeslice)
    {
        if (config.Enable)
        {
            timeCounter -= timeslice;
            if (timeCounter<0)
            {
                timeCounter = config.PeriodSec;
                SendPlayersCount();
            }
        }
    }

    private void SendPlayersCount()
    {
        array<Man> players = new array<Man>; 
		GetGame().GetPlayers(players);
        string message = string.Format(config.Message, players.Count());
        playerInfoSystem.SendMessage(message);
    }
}