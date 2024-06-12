CREATE OR REPLACE FUNCTION execute_project_adding2() RETURNS TRIGGER
AS $$
BEGIN
	CALL update_sales_project_number(NEW.sale_id);
	RETURN NEW;
	
END;
$$ LANGUAGE plpgsql;