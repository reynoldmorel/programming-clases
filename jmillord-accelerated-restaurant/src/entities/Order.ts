import { Client } from './Client'
import { Cashier } from './Cashier'
import { OrderDetails } from './OrderDetail'
import { Md5 } from 'ts-md5/dist/md5'

export class Order {
  private id: string;
  private transactionDate: Date
  private client: Client;
  private cashier: Cashier;
  private orderDetails: OrderDetails
  private totalAmount: number;

  constructor() { }

  public getId(): string {
    return this.id;
  }

  public setId(id: string): void {
    this.id = id;
  }

  public getTransactionDate(): Date {
    return this.transactionDate;
  }

  public setTransactionDate(transactionDate: Date): void {
    this.transactionDate = transactionDate;
  }

  public getClient(): Client {
    return this.client;
  }

  public setClient(client: Client): void {
    this.client = client;
  }

  public getCashier(): Cashier {
    return this.cashier;
  }

  public setCashier(cashier: Cashier): void {
    this.cashier = cashier;
  }

  public getOrderDetails(): OrderDetails {
    return this.orderDetails;
  }

  public setOrderDetails(orderDetails: OrderDetails): void {
    this.orderDetails = orderDetails;
  }

  public getTotalAmount(): number {
    return this.totalAmount;
  }

  public setTotalAmount(totalAmount: number): void {
    this.totalAmount = totalAmount;
  }

  public hashCode() {
    return Md5.hashStr(this.id)
  }



}