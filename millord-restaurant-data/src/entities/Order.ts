import { Client } from './Client'
import { Cashier } from './Cashier'
import { OrderDetails } from './OrderDetail'
import { Md5 } from 'ts-md5/dist/md5'

export class Order {
  private id?: string;
  private transactionDate?: Date
  private client?: Client;
  private cashier?: Cashier;
  private orderDetails?: OrderDetails
  private totalAmount?: number;

  constructor() { }

  public getId(): string | undefined {
    return this.id;
  }

  public setId(id: string): void {
    this.id = id;
  }

  public getTransactionDate(): Date | undefined {
    return this.transactionDate;
  }

  public setTransactionDate(transactionDate: Date): void {
    this.transactionDate = transactionDate;
  }

  public getClient(): Client | undefined {
    return this.client;
  }

  public setClient(client: Client): void {
    this.client = client;
  }

  public getCashier(): Cashier | undefined {
    return this.cashier;
  }

  public setCashier(cashier: Cashier): void {
    this.cashier = cashier;
  }

  public getOrderDetails(): OrderDetails | undefined {
    return this.orderDetails;
  }

  public setOrderDetails(orderDetails: OrderDetails): void {
    this.orderDetails = orderDetails;
  }

  public getTotalAmount(): number | undefined {
    return this.totalAmount;
  }

  public setTotalAmount(totalAmount: number): void {
    this.totalAmount = totalAmount;
  }

  public hashCode() {
    return Md5.hashStr(this.id)
  }




}
