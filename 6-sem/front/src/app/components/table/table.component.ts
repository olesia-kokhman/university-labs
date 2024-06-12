import { Component, OnInit} from '@angular/core';
import { CommonModule } from '@angular/common';
import { Lead } from '../../models/lead.model'
import { CrudService } from '../../services/crud.service'
import { FormsModule } from '@angular/forms';

@Component({
  selector: 'app-table',
  standalone: true,
  templateUrl: './table.component.html',
  styleUrl: './table.component.css', 
  imports: [CommonModule, FormsModule]
})

export class TableComponent implements OnInit{
  leads: Lead[] = [];
  showTable: boolean = false;
  
  new_id: number;
  new_name: string;
  new_location: string;
  new_status: number;
  new_date: Date;

  constructor(private crudService: CrudService) {
    this.new_id = 0;
    this.new_name = "";
    this.new_location = "";
    this.new_status = 1;
    this.new_date = new Date();
  }


  ngOnInit(): void {
   this.getLeads();
  }

  getLeads(): void {
    this.crudService.getLeads().subscribe({
      next: (response: Lead[]) => {
        this.leads = response; // Assign the retrieved leads to the leads property
        console.log('Leads got successfully:', this.leads);
        this.showTable = true;

      },
      error: (err) => {
        console.error('Error getting lead:', err);
        // Handle error response here
      }})
  }

  createLead() {
    
    const leadToAdd: Lead = {
      id: this.new_id,
      name: this.new_name,
      location: this.new_location,
      status: this.new_status,
      created_date: this.new_date
    };

    this.crudService.createLead(leadToAdd).subscribe({
      next: (response) => {
        console.log('Lead created successfully:', response);
        this.getLeads();
      },
      error: (err) => {
        console.error('Error creating lead:', err);
        // Handle error response here
      }})
  }

  getLeadById(): void {
    
    this.crudService.getLeadById(2).subscribe({
      next: (lead: Lead) => {
        console.log('Lead with ID', 2, 'retrieved successfully:', lead);
        this.getLeads();
      },
      error: (err) => {
        console.error('Error getting lead with ID', 2, ':', err);
      }
    });
  }

  updateLead(): void {
    var id = this.new_id;

    const leadToUpdate: Lead = {
      id: this.new_id,
      name: this.new_name,
      location: this.new_location,
      status: this.new_status,
      created_date: this.new_date
    };

    this.crudService.updateLead(id, leadToUpdate).subscribe({
      next: () => {
        console.log('Lead with ID', id, 'updated successfully.');
        this.getLeads();
      },
      error: (err) => {
        console.error('Error updating lead with ID', id, ':', err);
      }
    });
  }

  deleteLead(): void {
    var id = this.new_id
    this.crudService.deleteLead(id).subscribe({
      next: () => {
        console.log('Lead with ID', id, 'deleted successfully.');
        this.getLeads();
      },
      error: (err) => {
        console.error('Error deleting lead with ID', id, ':', err);
      }
    });
  }

}
