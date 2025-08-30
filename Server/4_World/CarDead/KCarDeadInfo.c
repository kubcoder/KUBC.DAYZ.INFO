class KCarDeadInfo
{
    private ref KCCarDeadConfig config;

    private ref KCPlayerInfo playerInfoSystem;

    void KCarDeadInfo(KCPlayerInfo playerInfo, KCCarDeadConfig carDeadConfig)
    {
        config = carDeadConfig;
        playerInfoSystem = playerInfo;
    }

    bool SendMessage(PlayerBase player, Object killer)
    {
        KCInfo.Log("Обработка информации об ДТП");
        Transport transport = Transport.Cast(killer);
        if (transport)
        {
            SendCar(player, transport);
            return true;
        }
        if (player == killer)
        {
            HumanCommandVehicle hcv = player.GetCommand_Vehicle();
            if (hcv)
            {
                KCInfo.Log("Транспорт найден:"+hcv);
                transport = Transport.Cast(hcv.GetTransport());
                SendCar(player, transport);
                return true;
            }
        }
        return false;
    }

    private void SendCar(PlayerBase player, Transport transport)
    {
        if (config.Enable)
        {
            PlayerBase driver = PlayerBase.Cast(transport.CrewMember(DayZPlayerConstants.VEHICLESEAT_DRIVER));
            if (driver)
            {
                if (driver==player)
                {
                    playerInfoSystem.SendMessage(string.Format(config.MessageDriver, player.GetIdentity().GetName(), transport.GetDisplayName()));
                }
                else
                {
                    playerInfoSystem.SendMessage(string.Format(config.Message, player.GetIdentity().GetName(), driver.GetIdentity().GetName(), transport.GetDisplayName()));
                }
            }
            else
            {
                playerInfoSystem.SendMessage(string.Format(config.MessageNoDriver, player.GetIdentity().GetName(), transport.GetDisplayName()));
            }
        }        
    }
}