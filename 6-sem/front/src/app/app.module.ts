import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { FormsModule } from '@angular/forms';
import { HttpClientModule} from '@angular/common/http';
import { RouterModule } from '@angular/router';
import { CommonModule } from '@angular/common'; 

import { TableComponent } from './components/table/table.component'; 
import { AppComponent } from './app.component';
import { CrudService } from './services/crud.service';


@NgModule({
  declarations: [
    AppComponent,
  ],
  imports: [
    BrowserModule,
    FormsModule,
    HttpClientModule,
    RouterModule.forRoot([]) ,
    CommonModule
    
  ],
  providers: [CrudService],
  bootstrap: [AppComponent] 
})

export class AppModule { }
