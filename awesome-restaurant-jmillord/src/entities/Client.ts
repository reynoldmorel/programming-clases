import { User } from './User'


export class Client extends User {

  private _code?: string

  constructor() {
    super()
  }

  get code(): string | undefined {
    return this._code
  }

  set code(value: string | undefined) {
    this._code = value

  }

}