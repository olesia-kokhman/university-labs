package org.crossplatformprogramming;

@FunctionalInterface
public interface IConverter<T> {
    T convertTo(String input);
}
