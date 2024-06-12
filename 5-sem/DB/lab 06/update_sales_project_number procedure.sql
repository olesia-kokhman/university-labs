CREATE OR REPLACE PROCEDURE update_sales_project_number(sale_id INTEGER)
AS $$
DECLARE
	sales_cursor CURSOR FOR 
		SELECT public."Sales".id FROM public."Sales";
	sales_id INTEGER;
BEGIN
	OPEN sales_cursor;
	LOOP
		FETCH NEXT FROM sales_cursor INTO sales_id;
		EXIT WHEN NOT FOUND;
		
		IF sales_id = sale_id THEN
			UPDATE public."Sales"
			SET project_number = COALESCE(project_number, 0) + 1
			WHERE id = sales_id;
			
			RAISE NOTICE 'Project number of sale - % was updated to', sales_id;
		END IF;
	END LOOP;
	CLOSE sales_cursor;
END;
$$ LANGUAGE plpgsql;

