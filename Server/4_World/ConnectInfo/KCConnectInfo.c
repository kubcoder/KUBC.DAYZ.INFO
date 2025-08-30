/// @brief Инструмент отправки сообщений о подключении отключении игрока
class KCConnectInfo
{
    private ref KCConnectionInfoConfig config;

    private ref KCPlayerInfo playerInfoSystem;

    void KCConnectInfo(KCPlayerInfo playerInfo, KCConnectionInfoConfig connectionConfig)
    {
        config = connectionConfig;
        playerInfoSystem = playerInfo;
    }

    void OnConnection(PlayerIdentity identity)
    {
        if (config.Enable)
        {
            string message = string.Format(config.MessageConnect, identity.GetName());
            playerInfoSystem.SendMessage(message);
        }
    }

    void OnDisconect(PlayerIdentity identity)
    {
        if (config.Enable)
            {
                if (identity)
                {
                    string message = string.Format(config.MessageDisconect, identity.GetName());
                    playerInfoSystem.SendMessage(message);
                }
                else
                {
                    KCInfo.Log("Событие отключения игрока без идентификации", KCLogLevel.Warning);
                }
                
            }
    }
}