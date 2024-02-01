// @ts-check

/**
 * The number of work hours per day
 */
const WORK_HOURS_PER_DAY = 8;

/*
 * The number of billable days in a month
 */
const BILLABLE_DAYS_IN_MONTH = 22;

/**
 * The day rate, given a rate per hour
 *
 * @param {number} ratePerHour
 * @returns {number} the rate per day
 */
export function dayRate(ratePerHour) {
    return WORK_HOURS_PER_DAY * ratePerHour;
}

/**
 * Calculates the number of days in a budget, rounded down
 *
 * @param {number} budget: the total budget
 * @param {number} ratePerHour: the rate per hour
 * @returns {number} the number of days
 */
export function daysInBudget(budget, ratePerHour) {
    return Math.floor(budget / dayRate(ratePerHour));
}

/**
 * Calculates the discounted rate for large projects, rounded up
 *
 * @param {number} ratePerHour
 * @param {number} numDays: number of days the project spans
 * @param {number} discount: for example 20% written as 0.2
 * @returns {number} the rounded up discounted rate
 */
export function priceWithMonthlyDiscount(ratePerHour, numDays, discount) {
    const months = Math.floor(numDays / BILLABLE_DAYS_IN_MONTH);
    const daysWithDiscount = months * BILLABLE_DAYS_IN_MONTH;
    const daysWithoutDiscount = numDays - daysWithDiscount;
    return Math.ceil(
	    (daysWithDiscount * dayRate(ratePerHour) * (1 - discount))
	    + (daysWithoutDiscount * dayRate(ratePerHour))
    );
}
