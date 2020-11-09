import { User } from './User'


export class Cashier extends User {
  
  constructor() { 
    super()
  }
  
  get id(): string | undefined {
    return this._id
  }
}