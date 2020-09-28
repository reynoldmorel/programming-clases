import { Client } from './Client'
import { Cashier } from './Cashier'
import { OrderDetails } from './OrderDetail'
import { Md5 } from 'ts-md5/dist/md5'

export class Order {
<<<<<<< HEAD
  private _id?: string;
  private _transactionDate?: Date
  private _client?: Client;
  private _cashier?: Cashier;
  private _orderDetails?: OrderDetails
  private _totalAmount?: number;

  constructor() { }

  get id(): string | undefined {
    return this._id
  }

  set id(value: string | undefined) {
    this._id = value
  }

  get transactionDate(): Date | undefined {
    return this._transactionDate
  }

  set transactionDate(value: Date | undefined) {
    this._transactionDate = value
  }

  get client(): Client | undefined {
    return this._client
  }

  set client(value: Client | undefined) {
    this._client = value
  }

  get cashier(): Cashier | undefined {
    return this._cashier
  }

  set cashier(value: Cashier | undefined) {
    this._cashier = value
  }

  get orderDetails(): OrderDetails | undefined {
    return this._orderDetails
  }

  set orderDetails(value: OrderDetails | undefined) {
    this._orderDetails = value
  }


  get totalAmount(): number | undefined {
    return this._totalAmount
  }

  set totalAmount(value: number | undefined) {
    this._totalAmount = value
  }


=======
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




>>>>>>> e5e309a229e3d2976167e70c766c15802cac1c9b
}
