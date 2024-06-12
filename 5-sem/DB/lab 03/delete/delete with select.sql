DELETE FROM public."Payments"
	WHERE id=(SELECT id FROM public."Projects" WHERE id=20)