class KCDeadInfo
{
    private ref KCPlayerDead playerDead;

    private ref KCExplosiveInfo explosive;

    private ref KCPlayerKill playerKill;

    private ref KCarDeadInfo carDead;

    private ref KCAiKillInfo aiKill;

    void KCDeadInfo(KCInfoConfig config, KCPlayerInfo playerInfoSystem)
    {
        playerDead = new KCPlayerDead(playerInfoSystem, config.PlayerDead);
        explosive = new KCExplosiveInfo(playerInfoSystem, config.Explosive);
        playerKill = new KCPlayerKill(playerInfoSystem, config.PlayerKill);
        carDead = new KCarDeadInfo(playerInfoSystem, config.CarDead);
        aiKill = new KCAiKillInfo(playerInfoSystem, config.AiKill);
    }

    void SendMessage(PlayerBase player, Object killer)
    {
        KCInfo.Log("Серть игрока " + player.GetIdentity().GetName() + "("+player+")" + ", убийца: " + killer);
        if (carDead.SendMessage(player, killer))
        {
            return;
        }
        if (playerDead.SendMessage(player, killer))
        {
            return;
        }
        if (explosive.SendMessage(player, killer))
        {
            return;
        }
        if (playerKill.SendMessage(player, killer))
        {
            return;
        }
        aiKill.SendMessage(player, killer);
    }
}