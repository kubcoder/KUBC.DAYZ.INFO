class KCPlayerDead
{
     private ref KCPlayerDeadConfig config;

    private ref KCPlayerInfo playerInfoSystem;

    void KCPlayerDead(KCPlayerInfo playerInfo, KCPlayerDeadConfig playerDeadConfig)
    {
        config = playerDeadConfig;
        playerInfoSystem = playerInfo;
    }

    bool SendMessage(PlayerBase player, Object killer)
    {
        KCInfo.Log("Обработка информации о смерти без лишних причин");
        if (player == killer)
        {
            if (config.Enable)
            {
                PlayerIdentity identity = player.GetIdentity();
                if (identity)
                {
                    string name = identity.GetName();
                    if (player.GetStatEnergy().Get() == 0)
                    {
                        playerInfoSystem.SendMessage(string.Format(config.MessageEnergy, name));
                        return true;
                    }
                    if (player.GetStatWater().Get() == 0)
                    {
                        playerInfoSystem.SendMessage(string.Format(config.MessageWater, name));
                        return true;
                    }
                    if (player.GetHealth("","Blood") == 0)
                    {
                        playerInfoSystem.SendMessage(string.Format(config.MessageBlood, name));
                        return true;
                    }
                    playerInfoSystem.SendMessage(string.Format(config.Message, name));
                }
            }
            return true;
        }
        return false;
    }
}