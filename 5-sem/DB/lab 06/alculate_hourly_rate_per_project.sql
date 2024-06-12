CREATE OR REPLACE FUNCTION calculate_hourly_rate_per_project(
	project_length_in_days INTEGER,
	budget INTEGER)
RETURNS DECIMAL 
AS $$
DECLARE
	hours_per_day INTEGER := 8;
	hourly_rate DECIMAL;
BEGIN
	hourly_rate := project_length_in_days * hours_per_day / budget::DECIMAL; 
	RETURN hourly_rate;
END;
$$ LANGUAGE plpgsql;
