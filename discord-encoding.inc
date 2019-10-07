stock DCC_EncodeString(const src[], dest[], max_size = sizeof dest)
{
	static const s_map[][][] =
	{
		{"�", "¤"},
		{"�", "¦"},
		{"�", "§"},
		{"�", "¨"},
		{"�", "©"},
		{"�", "«"},
		{"�", "¬"},
		{"�", "­"},
		{"�", "®"},
		{"�", "°"},
		{"�", "±"},
		{"�", "´"},
		{"�", "µ"},
		{"�", "¶"},
		{"�", "·"},
		{"�", "¸"},
		{"�", "»"},
		{"�", "Á"},
		{"�", "Â"},
		{"�", "Ä"},
		{"�", "Ç"},
		{"�", "É"},
		{"�", "Ë"},
		{"�", "Í"},
		{"�", "Î"},
		{"�", "Ó"},
		{"�", "Ô"},
		{"�", "Ö"},
		{"�", "×"},
		{"�", "Ú"},
		{"�", "Ü"},
		{"�", "Ý"},
		{"�", "ß"},
		{"�", "á"},
		{"�", "â"},
		{"�", "ä"},
		{"�", "ç"},
		{"�", "é"},
		{"�", "ë"},
		{"�", "í"},
		{"�", "î"},
		{"�", "ó"},
		{"�", "ô"},
		{"�", "ö"},
		{"�", "÷"},
		{"�", "ú"},
		{"�", "ü"},
		{"�", "ý"},
		{"�", "Ă"},
		{"�", "ă"},
		{"�", "Ą"},
		{"�", "ą"},
		{"�", "Ć"},
		{"�", "ć"},
		{"�", "Č"},
		{"�", "č"},
		{"�", "Ď"},
		{"�", "ď"},
		{"�", "Đ"},
		{"�", "đ"},
		{"�", "Ę"},
		{"�", "ę"},
		{"�", "Ě"},
		{"�", "ě"},
		{"�", "Ĺ"},
		{"�", "ĺ"},
		{"�", "Ľ"},
		{"�", "ľ"},
		{"�", "Ł"},
		{"�", "ł"},
		{"�", "Ń"},
		{"�", "ń"},
		{"�", "Ň"},
		{"�", "ň"},
		{"�", "Ő"},
		{"�", "ő"},
		{"�", "Ŕ"},
		{"�", "ŕ"},
		{"�", "Ř"},
		{"�", "ř"},
		{"�", "Ś"},
		{"�", "ś"},
		{"�", "Ş"},
		{"�", "ş"},
		{"�", "Š"},
		{"�", "š"},
		{"�", "Ţ"},
		{"�", "ţ"},
		{"�", "Ť"},
		{"�", "ť"},
		{"�", "Ů"},
		{"�", "ů"},
		{"�", "Ű"},
		{"�", "ű"},
		{"�", "Ź"},
		{"�", "ź"},
		{"�", "Ż"},
		{"�", "ż"},
		{"�", "Ž"},
		{"�", "ž"},
		{"�", "ˇ"},
		{"�", "˘"},
		{"�", "˙"},
		{"�", "˛"},
		{"�", "˝"},
		{"�", "–"},
		{"�", "—"},
		{"�", "‘"},
		{"�", "’"},
		{"�", "‚"},
		{"�", "“"},
		{"�", "”"},
		{"�", "„"},
		{"�", "†"},
		{"�", "‡"},
		{"�", "•"},
		{"�", "…"},
		{"�", "‰"},
		{"�", "‹"},
		{"�", "›"},
		{"�", "€"},
		{"�", "™"}
	};

	new const
	    len = strlen(src);

	if(len >= max_size) //not enough minimum space to fit src
	{
		return 0;
	}

	new
		index;

	for(new i, j = len, bool:done; i < j; i++, done = false)
	{
	    for(new k; k < sizeof(s_map); k++)
	    {
			if(src[i] == s_map[k][0][0])
			{
			    new
					mapLen = strlen(s_map[k][1]);

				if(index + mapLen >= max_size) //overflow
				{
					dest[0] = 0;
					return 0;
				}

				for(new l; l < mapLen; l++)
				{
					dest[index++] = s_map[k][1][l];
				}
				done = true;
				break;
			}
		}
		if(!done)
		{
			dest[index++] = src[i];
		}
	}
	dest[index] = 0;
	return 1;
}
