SELECT "Low Salary" as category, sum(if(income < 20000,1,0)) as accounts_count from Accounts
union 
SELECT "Average Salary" as category, sum(if(income <= 50000 and income >= 20000,1,0)) as accounts_count from Accounts
union 
SELECT "High Salary" as category, sum(if(income > 50000,1,0)) as accounts_count from Accounts