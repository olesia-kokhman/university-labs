import { Injectable } from '@angular/core';
import { Lead } from '../models/lead.model'
import { Observable } from 'rxjs';
import { HttpClient } from '@angular/common/http';

@Injectable({
  providedIn: 'root'
})
export class CrudService {

  private apiUrl = 'https://localhost:7015/api/Lead'; // Replace with your backend API URL

  constructor(private http: HttpClient) { }

  getLeads(): Observable<Lead[]> {
    return this.http.get<Lead[]>(`${this.apiUrl}`);
  }

  getLeadById(id: number): Observable<Lead> {
    return this.http.get<Lead>(`${this.apiUrl}/${id}`);
  }

  createLead(lead: Lead): Observable<Lead> {
    return this.http.post<Lead>(this.apiUrl, lead);
  }

  updateLead(id: number, leadData: Lead): Observable<Lead> {
    return this.http.put<Lead>(`${this.apiUrl}/${id}`, leadData);
  }

  deleteLead(id: number): Observable<void> {
    return this.http.delete<void>(`${this.apiUrl}/${id}`);
  }
}
