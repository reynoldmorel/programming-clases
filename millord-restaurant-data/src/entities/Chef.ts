import { User } from './User'


export class Chef extends User {
  constructor(id?: string) {
    super(id)
  }
  public Chef(id: string) {
    return id
  }


}