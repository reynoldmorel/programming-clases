import { Client } from './Client'
import { Cashier } from './Cashier'
import { OrderDetails } from './OrderDetail'
import { Md5 } from 'ts-md5/dist/md5'

export class Order {
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


}
