modded class MissionServer
{
    /// @brief  Модуль отправки сообщений игрокам
    private ref KCPlayerInfo playerInfoSystem;

    /// @brief Система информирования о подключении/отключении игроков
    private ref KCConnectInfo connectInfoSystem;

    /// @brief Система информирования о колличестве игроков
    private ref KCPlayersCount playersCountSystem;
    
    

    override void OnInit()
    {
        InfoConfig = new KCInfoConfig();
        playerInfoSystem = new KCPlayerInfo();
        connectInfoSystem = new KCConnectInfo(playerInfoSystem, InfoConfig.ConnectionInfo);
        playersCountSystem = new KCPlayersCount(playerInfoSystem, InfoConfig.PlayersCount);
        SuicideInfoSystem = new KCSuicideInfo(playerInfoSystem, InfoConfig.SuicideInfo);
        PlayerDeadInfoSystem = new KCDeadInfo(InfoConfig, playerInfoSystem);
        super.OnInit(); 
        
    }

    override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
    {
        super.InvokeOnConnect(player,identity);
        if (connectInfoSystem)
        {
            connectInfoSystem.OnConnection(identity);
        }
    }

    override void PlayerDisconnected(PlayerBase player, PlayerIdentity identity, string uid)
    {
        super.PlayerDisconnected(player, identity, uid);
        if (connectInfoSystem)
        {
            connectInfoSystem.OnDisconect(identity);
        }
    }

    

    /// @brief Вызывается постоянно для обновления игровой ситуации
    /// @param timeslice сколько времени прошло с последнего вызова, в секундах.
    override void OnUpdate(float timeslice)
    {
        super.OnUpdate(timeslice);
        if (playersCountSystem)
        {
            playersCountSystem.OnTick(timeslice);
        }
    }
}