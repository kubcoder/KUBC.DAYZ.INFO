class KCAiKillInfo
{
    private ref KCAiKillConfig config;

    private ref KCPlayerInfo playerInfoSystem;

    void KCAiKillInfo(KCPlayerInfo playerInfo, KCAiKillConfig aiKillonfig)
    {
        config = aiKillonfig;
        playerInfoSystem = playerInfo;
    }

    bool SendMessage(PlayerBase player, Object killer)
    {
        KCInfo.Log("Обработка информации об AI");
        if (player.GetIdentity())
        {
            playerInfoSystem.SendMessage(string.Format(config.Message, player.GetIdentity().GetName(), killer.GetDisplayName()));
        }
        return true;
    }
}