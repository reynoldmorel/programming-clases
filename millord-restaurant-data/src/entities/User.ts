
import { Md5 } from 'ts-md5/dist/md5'


export abstract class User {
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