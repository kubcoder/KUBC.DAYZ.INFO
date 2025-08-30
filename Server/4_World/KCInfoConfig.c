/// @brief Класс конфигурации мода
class KCInfoConfig
{
    /// @brief Настройки отображения информации о подключении/оотключении игроков
    ref KCConnectionInfoConfig ConnectionInfo;


    /// @brief Настройки отображения информации о количестве игроков
    ref KCPlayersCountConfig PlayersCount;

    /// @brief Настройки отображения информации о количестве игроков
    ref KCSuicideInfoConfig SuicideInfo;

    ref KCPlayerDeadConfig PlayerDead;

    ref KCExplosiveConfig Explosive;

    ref KCPlayerKillConfig PlayerKill;

    ref KCCarDeadConfig CarDead;

    ref KCAiKillConfig AiKill;

    void KCInfoConfig()
    {
        KCInfoFilesFactory filesFactory = new KCInfoFilesFactory();
        filesFactory.CreatePaths();
        KCConnectInfoConfigFactory connectionInfoFactory = new KCConnectInfoConfigFactory(filesFactory);
        ConnectionInfo = connectionInfoFactory.Build();
        KCPlayersCountConfigFactory playersCountFactory = new KCPlayersCountConfigFactory(filesFactory);
        PlayersCount = playersCountFactory.Build();
        KCSuicideInfoConfigFactory suicideInfoFactory = new KCSuicideInfoConfigFactory(filesFactory);
        SuicideInfo = suicideInfoFactory.Build(); 
        KCPlayerDeadConfigFactory playerDeadConfigFactory = new KCPlayerDeadConfigFactory(filesFactory);
        PlayerDead = playerDeadConfigFactory.Build();
        KCExplosiveConfigFactory explosiveConfigFactory = new KCExplosiveConfigFactory(filesFactory);
        Explosive = explosiveConfigFactory.Build(); 
        KCPlayerKillConfigFactory playerKillConfigFactory = new KCPlayerKillConfigFactory(filesFactory);
        PlayerKill = playerKillConfigFactory.Build();
        KCCarDeadConfigFactory carDeadConfigFactory = new KCCarDeadConfigFactory(filesFactory);
        CarDead = carDeadConfigFactory.Build();
        KCAiKillConfigFactory aiKillConfigFactory = new KCAiKillConfigFactory(filesFactory);
        AiKill = aiKillConfigFactory.Build();
    }
}