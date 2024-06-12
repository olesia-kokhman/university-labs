import { Component, OnInit } from '@angular/core';
import { TableComponent } from './components/table/table.component'; 


@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrl: './app.component.css',
  imports: [TableComponent],
  standalone: true
})
export class AppComponent {
  title = 'angular-lab';
}
