
import { Md5 } from 'ts-md5/dist/md5'


export abstract class User {
<<<<<<< HEAD
  private _id?: string;
  private _name?: string;
  private _lastName?: string;
  private _age?: number;
  private _identification?: number;
  private _phone?: string;
  private _address?: string

  constructor() { }

  get id(): string | undefined {
    return this._id;
  }

  set id(value: string | undefined) {
    this._id = value
  }

  get name(): string | undefined {
    return this._name;
  }

  set name(value: string | undefined) {
    this._name = value;
  }

  get lastName(): string | undefined {
    return this._lastName
  }

  set lastName(value: string | undefined) {
    this._lastName = value
  }

  get age(): number | undefined {
    return this._age
  }

  set age(value: number | undefined) {
    this._age = value
  }

  get identification(): number | undefined {
    return this._identification
  }

  set identification(value: number | undefined) {
    this._identification = value
  }

  get phone(): string | undefined {
    return this._phone
  }

  set phone(value: string | undefined) {
    this._phone = value
  }

  get address(): string | undefined {
    return this._address
  }

  set address(value: string | undefined) {
    this._address = value
  }



}

=======
  private id?: string;
  private name?: string;
  private lastName?: string;
  private age?: number;
  private identification?: number;
  private phone?: string;
  private address?: string

  constructor(id?: string) {
    this.id = id
  }

  public getId(): string | undefined {
    return this.id
  }

  public setId(id: string): void {
    this.id = id;
  }

  public getName(): string | undefined {
    return this.name;
  }

  public setName(name: string): void {
    this.name = name;
  }

  public getLastName(): string | undefined {
    return this.lastName;
  }

  public setLastName(lastName: string): void {
    this.lastName = lastName;
  }

  public getAge(): number | undefined {
    return this.age;
  }

  public setAge(age: number): void {
    this.age = age;
  }

  public getIdentification(): number | undefined {
    return this.identification;
  }

  public setIdentification(identification: number): void {
    this.identification = identification;
  }

  public getPhone(): string | undefined {
    return this.phone;
  }

  public setPhone(phone: string): void {
    this.phone = phone;
  }

  public getAddress(): string | undefined {
    return this.address;
  }

  public setAddress(address: string): void {
    this.address = address;
  }

  public hashCode() {
    return Md5.hashStr(this.id)
  }

}
>>>>>>> e5e309a229e3d2976167e70c766c15802cac1c9b
