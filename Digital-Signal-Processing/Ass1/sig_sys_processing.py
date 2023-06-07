import numpy as np
import matplotlib.pyplot as plt
import scipy.signal as sig

""" Signals """
# Plot functions
def plot_signal(signal, figure):
    plt.figure(figure)
    # plt.stem(signal)
    plt.plot(signal)
    plt.xlabel('Time')
    plt.ylabel('Amplitude')
    plt.title('Signal')
    plt.show()


def plot_frequency(signal, figure):
    plt.figure(figure)
    plt.subplot(211)
    plt.plot(signal[0], signal[3], label='real')
    plt.plot(signal[0], signal[4], '--', label='img')
    plt.legend()
    plt.subplot(212)
    plt.plot(signal[0], signal[1], '--', label='mag')
    plt.plot(signal[0], signal[2], label='phase')
    plt.legend()
    plt.show()

# Convert the discrete-time signal to frequency domain
def convert_to_frequency_domain(signal):
    # Compute the Fast Fourier Transform (FFT)
    # which is a discrete Fourier transform algorithm
    # When the input data sequence x[n] is N-periodic,
    # can be computationally reduced to a discrete Fourier transform (DFT)
    # https://en.wikipedia.org/wiki/Discrete-time_Fourier_transform
    signal = np.array(signal)
    fft = np.fft.fft(signal)
    freq = np.fft.fftfreq(signal.shape[-1])
    magnitude = np.abs(fft)
    phase = np.angle(fft)
    real = np.real(fft)
    imag = np.imag(fft)
    return [freq, magnitude, phase, real, imag, fft]

# Revert back to time domain
def revert_to_time_domain(signal_freq):
    ifft = np.fft.ifft(signal_freq)
    return ifft


""" Systems """
def time_convolution(signal_1, signal_2):
    output = sig.convolve(signal_1, signal_2, mode='full')
    return output

def frequency_multiplication(signal_1, signal_2):
    # Pad the signals to the same length
    if len(signal_1) > len(signal_2):
        signal_2 = np.pad(signal_2, (0, len(signal_1) - len(signal_2)), 'constant')
    elif len(signal_1) < len(signal_2):
        signal_1 = np.pad(signal_1, (0, len(signal_2) - len(signal_1)), 'constant')
    # Convert to frequency domain
    signal_1_freq = np.fft.fft(signal_1)
    signal_2_freq = np.fft.fft(signal_2)
    output = signal_1_freq * signal_2_freq
    freq = np.fft.fftfreq(output.shape[-1])
    magnitude = np.abs(output)
    phase = np.angle(output)
    real = np.real(output)
    imag = np.imag(output)
    return [freq, magnitude, phase, real, imag, output]
    


""" ECG """
# Low pass filtering
def low_pass_filter(signal):
    b,a = sig.butter(4, 0.1, 'low', analog=False)
    output = sig.filtfilt(b, a, signal)
    return output

def high_pass_filter(signal):
    b,a = sig.butter(4, 0.5/180, 'high', analog=False)
    output = sig.filtfilt(b, a, signal)
    return output

def noise(strength):
    return np.random.normal(scale=strength, size = 640)
