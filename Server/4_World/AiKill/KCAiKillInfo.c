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
        ZombieBase zmb = ZombieBase.Cast(killer);
        if (zmd)
        {
            return TrySendMessage(player, killer);
        }
        AnimalBase animal = AnimalBase.Cast(killer);
        if (animal)
        {
            return TrySendMessage(player, killer);            
        }
        return false;
    }

    private bool TrySendMessage(PlayerBase player, Object killer)
    {
        if (config.Enable)
        {
            if (player.GetIdentity())
            {
                playerInfoSystem.SendMessage(string.Format(config.Message, player.GetIdentity().GetName(), killer.GetDisplayName()));
            }            
        }
        return true;
    }
}