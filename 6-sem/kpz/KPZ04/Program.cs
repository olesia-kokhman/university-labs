using KPZ04.Models;
using Microsoft.AspNetCore.Cors;
using Microsoft.EntityFrameworkCore;

var builder = WebApplication.CreateBuilder(args);

builder.Services.AddControllers();
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();
builder.Services.AddDbContext<SalesContext>(option => option.UseNpgsql(builder.Configuration
    .GetConnectionString("SalesPostgresql")));

builder.Services.AddCors(options =>
{
    options.AddPolicy("AllowOrigin", builder =>
    {
        builder.AllowAnyHeader()
               .AllowAnyMethod().AllowAnyOrigin();
       
    });
});

var app = builder.Build();


if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI();

    
}

app.UseHttpsRedirection();
app.UseCors("AllowOrigin");

app.UseAuthorization();


app.MapControllers();

app.Run();
