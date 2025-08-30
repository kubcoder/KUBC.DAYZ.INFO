class KCExplosiveInfo
{
    private ref KCExplosiveConfig config;

    private ref KCPlayerInfo playerInfoSystem;

    void KCExplosiveInfo(KCPlayerInfo playerInfo, KCExplosiveConfig explosiveConfig)
    {
        config = explosiveConfig;
        playerInfoSystem = playerInfo;
    }

    bool SendMessage(PlayerBase player, Object killer)
    {
        KCInfo.Log("Обработка информации об подрыве игрока");
        if (ExplosivesBase.Cast(killer))
        {
            if (config.Enable)
            {
                playerInfoSystem.SendMessage(string.Format(config.Message, player.GetIdentity().GetName(), killer.GetDisplayName()));
            }
            return true;
        }
        return false;
    }
}