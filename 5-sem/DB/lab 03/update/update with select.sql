UPDATE public."Projects_Developers"
	SET developers_id=(SELECT id FROM public."Developers" WHERE name='Michael Johnson')
	WHERE id=9