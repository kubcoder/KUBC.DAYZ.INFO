class KCSuicideInfo
{
    private ref KCSuicideInfoConfig config;

    private ref KCPlayerInfo playerInfoSystem;

    void KCSuicideInfo(KCPlayerInfo playerInfo, KCSuicideInfoConfig suicideInfoConfig)
    {
        config = suicideInfoConfig;
        playerInfoSystem = playerInfo;
    }

    void SendMessage(PlayerBase player)
    {
        if (config.Enable)
        {
            string message = string.Format(config.Message, player.GetIdentity().GetName());
            playerInfoSystem.SendMessage(message);
        }
    }
}