function my_plot(x, y, title_str, x_label, y_label)
    plot(x, y);
    title(title_str);
    grid on;
    box off;
    ylabel(y_label, "Rotation", 0);
    xlabel(x_label);
    setup_image_folder()
    exportgraphics(gcf, title_str + '.png', 'Resolution', 300); cd('..');
end

