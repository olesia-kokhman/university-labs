CREATE OR REPLACE FUNCTION calculate_days_to_contract(created_date DATE, connected_date DATE) 
RETURNS INTEGER 
AS $$
DECLARE
	days INTEGER;
BEGIN
	days := connected_date - created_date;
	RETURN days;
END;
$$ LANGUAGE plpgsql;

